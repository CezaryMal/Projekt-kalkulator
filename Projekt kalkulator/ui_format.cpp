// ui_format.cpp
#include "ui_format.h"
#include <iostream>
#include <iomanip>
#include <limits>
#include <sstream>
#include <cmath>
#include <cstdlib>
#if defined(_WIN32)
#include <windows.h>
#undef min
#undef max
#endif
using namespace std;

namespace {
// Wyrownuje przekazany tekst do srodka ramki o okreslonej szerokosci
string centerText(const string& text, int width) {
    if (width <= static_cast<int>(text.size())) return text;
    int totalPadding = width - static_cast<int>(text.size());
    int leftPadding = totalPadding / 2;
    int rightPadding = totalPadding - leftPadding;
    return string(static_cast<size_t>(leftPadding), ' ')
        + text
        + string(static_cast<size_t>(rightPadding), ' ');
}
}

// Usuwa tresc konsoli w zaleznosci od systemu operacyjnego
void clearout() {
#if defined(_WIN32) || defined(_WIN64)
    system("cls");
#else
    system("clear");
#endif
}

// Informuje uzytkownika o pauzie i czeka na wcisniecie Enter
void waitEnter() {
    cout << "\nPress [Enter] to continue...";
    cin.get();
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

// Wyswietla tablice elementow menu wraz z tytulem w ozdobnej ramce
void showmenu(const vector<MenuItem>& items, const string& title) {
    constexpr int width = 40;
    const string border(width, '-');
    cout << '+' << border << "+\n";
    cout << "| " << centerText(title, width - 2) << " |\n";
    cout << '+' << border << "+\n";
    for (const auto& item : items) {
        ostringstream row;
        if (item.displayId) {
            row << item.id << ". ";
        }
        row << item.label;
        cout << "| " << left << setw(width - 2) << row.str() << " |\n";
    }
    cout << '+' << border << "+\n";
}
void border(){
    constexpr int width = 40;
    const string border(width, '-');
    cout << '+' << border << "+\n";
}
string formatNumber(long double value) {// Funkcja formatująca liczbę zmiennoprzecinkową do stringa z usuniętymi nadmiarowymi zerami i zaogrąglaniem
    constexpr int kFractionDigits = 10;// liczba cyfr po przecinku
    const long double scale = powl(10.0L, static_cast<long double>(kFractionDigits));// skala do zaokrąglania
    long double rounded = roundl(value * scale) / scale;// zaokrąglanie liczby

    ostringstream oss;// strumień do konwersji na string
    oss << fixed << setprecision(kFractionDigits) << rounded;// ustawienie formatu i precyzji
    string out = oss.str();// konwersja strumienia na string
    size_t pos = out.find_last_not_of('0');// znajdź ostatnią cyfrę nie będącą zerem
    if (pos == string::npos) {// jeśli wszystkie są zerami
        return "0";
    }
    if (out[pos] == '.') {// jeśli ostatnia niezerowa cyfra to kropka dziesiętna
        pos--;// cofamy się o jeden znak
    }
    out.erase(pos + 1);// usuwamy nadmiarowe zera
    if (out == "-0") {// obsługa przypadku -0
        out = "0";// zamiana na 0
    }
    return out;// zwracamy sformatowany string
}
long double readsafecheck(const string& prompt){
    const int digits = numeric_limits<long double>::digits10;
    const long double limit = powl(10.0L, static_cast<long double>(digits));
    while (true){
        cout << prompt;
        long double x;
        cin >> x;
        if(cin.fail()){
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter a valid number." << endl;
            continue;
        }
        if(fabsl(x) >= limit){
            cout << "Input out of range ( x <10^" << digits << "). \n Please enter number between -" << limit << " and " << limit << "." << endl;
            continue;
        }
        return x;
    }
}