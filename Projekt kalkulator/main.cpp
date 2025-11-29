/*
Projekt kalkulatora konsolowego w C++

Semest 1 Grupa D2
1. Cezary Małgorzaciak
2. Patryk Podleżyński
3. Kacper Łosicki
4. Dawid Płachta
5. Krzysiek Kramarski


*/


#include <iostream>
#include <cstdlib>
#include <chrono>
#include <thread>
#include <cctype>
#include <cmath>
#include <iomanip>
#include <string>
#include <sstream>

using namespace std;

string formatNumber(long double value) {// Funkcja formatująca liczbę zmiennoprzecinkową do stringa z usuniętymi nadmiarowymi zerami i zaogrąglaniem
    constexpr int kFractionDigits = 12;// liczba cyfr po przecinku
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


void waitEnter() {//Do pauzowania programu
    cout << "\nPress [Enter] to continue...";
    cin.get();
	cin.clear();// czyści błąd strumienia jeśli wystąpił np. jak ktoś przypadkiem cokolwiek napisze zamiast tylko wcisnąć enter
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

}
void clearout() {//Ta funkcja odpowiedzialna jest za sprawdzenie systemu na jakim jest używany program i umożliwić czyszczenie terminala.
	//Dodałem to ze względu pisania na początku kodu na Mac'u a potem testowanie na Windowsie
#if defined(_WIN32) || defined(_WIN64)
    system("cls");
#else
    system("clear");
#endif
}

void showmenu() {//Pokazuje menu kalkulatora !!!To do zmiany w formatowanie tabeli
    cout << "Choose from menu:" << endl;
    cout << "1. Addition" << endl; // dodawanie
    cout << "2. Substract" << endl; // odejmowanie
    cout << "3. Multiplication" << endl; // mnożenie
    cout << "4. Division" << endl; // dzielenie
    cout << "5. Exponentiation" << endl; // potęgowanie
    cout << "6. Root" << endl; // pierwiastkowanie
    cout << "7. Pi constant" << endl; // stała pi
    cout << "8. Euler's number" << endl; // stała e
    cout << "9. Sine (sin)" << endl; // sinus
    cout << "10. Cosine (cos)" << endl; // cosinus
    cout << "11. Tangent (tan)" << endl; // tangens
    cout << "12. Cotangent (cot)" << endl; // cotangens
    cout << "0. Exit" << endl; // wyjście z programu
}


int main() {
    cout << fixed; // Ustawienie precyzji wyświetlania liczb zmiennoprzecinkowych
	setlocale(LC_ALL, "");//Ustawienie lokalizacji na polską żeby obsługiwać polskie znaki
    while (true) {// Pętla do ciągłego działania programu
        clearout(); // czyścimy ekran przed pokazaniem menu
        showmenu(); // wyświetlamy menu
        string choice;
        cout << "Input your choice: ";
        cin >> choice; // czytamy wybór użytkownika jako tekst (pozwala na 10,11,12)

        int opt = -1;
        // Parsowanie wyboru: akceptujemy wielocyfrowe liczby (np. 10, 11, 12).
        bool ok = true;
        if (choice.empty()) ok = false;//sprawdzamy czy nie jest puste
        for (char ch : choice) if (!isdigit(static_cast<unsigned char>(ch))) ok = false;//sprawdzamy czy każda cyfra jest cyfrą
        if (!ok) {
            // Nieprawidłowy format wyboru (np. litery) — prosimy o ponowny wybór
            cout << "ERROR!" << endl;
            cout << "Unknown choice. Input 0-12." << endl;
            waitEnter();
            continue;
        }
        try {
            opt = stoi(choice); // konwersja na int
        } catch (...) {// obsługa wyjątków na wypadek bardzo dużych liczb
            cout << "ERROR!" << endl;
            cout << "Unknown choice. Input 0-12." << endl;
            waitEnter();
            continue;
        }

        // Główna instrukcja wyboru. Każdy case obsługuje jedną pozycję menu.
        switch (opt) {
        case 0:
            // Wyjście z programu: czyścimy ekran i kończymy działanie.
            clearout();
            cout << "See you next time!" << endl;
            this_thread::sleep_for(chrono::seconds(2));
            return 0;

        case 1:{//Dodawanie
            clearout();
            cout<<"Addition"<<endl;
            long double a = 0.0L, b = 0.0L;
            long double result = 0.0L;
            cout << "Input a: "; cin >> a;
            cout << "Input b: "; cin >> b;
            cout << "DOKOŃCZYĆ KODOWANIE" << endl;
            result = a + b;
            cout << formatNumber(a) << " + " << formatNumber(b) << " = " << formatNumber(result) << endl;
            waitEnter();
            break;
        }
        case 2:{
            clearout();
            cout<<"Substraction"<<endl;
            long double a = 0.0L, b = 0.0L;
            long double result = 0.0L;
            cout << "Input a: "; cin >> a;
            cout << "Input b: "; cin >> b;
            cout << "DOKOŃCZYĆ KODOWANIE" << endl;
            result = a - b;
            cout << formatNumber(a) << " - " << formatNumber(b) << " = " << formatNumber(result) << endl;
            waitEnter();
            break;
        }
        case 3:{
            clearout();
            cout<<"Multiplication"<<endl;
            long double a = 0.0L, b = 0.0L;
            long double result = 0.0L;
            cout << "Input a: "; cin >> a;
            cout << "Input b: "; cin >> b;
            cout << "DOKOŃCZYĆ KODOWANIE" << endl;
            result = a * b;
            cout << formatNumber(a) << " * " << formatNumber(b) << " = " << formatNumber(result) << endl;//wyświetlanie wyniku
            waitEnter();
            break;
        }
        case 4: { // Dzielenie: sprawdzamy czy nie dzielimy przez zero, jeśli OK obliczamy wynik
            clearout();
            cout << "Division" << endl;
            long double a = 0.0L, b = 0.0L;
            long double result = 0.0L;
            cout << "Input a (numerator): "; cin >> a;
            cout << "Input b (denominator): "; cin >> b;

               
            if (fabsl(b) < 1e-18L) {
                // b (mianownik) jest praktycznie zerem -> wyświetlamy błąd
                cout << "Error: division by zero is not allowed." << endl;
            } else {
                result = a / b;
                cout << formatNumber(a) << " / " << formatNumber(b) << " = " << formatNumber(result) << endl;
                cout << "DOKOŃCZYĆ KODOWANIE" << endl;
                waitEnter();
            }
            break;
        }
        waitEnter();
        break;
        

        case 5: {//Potęgowanie
            clearout();
            cout << "Exponentiation" << endl;
            long double a = 0.0L, b = 0.0L;
            long double result = 0.0L;
            cout << "Input a: "; cin >> a;
            cout << "To the power of: "; cin >> b;
            result = powl(a, b);
            cout << formatNumber(a) << " ^ " << formatNumber(b) << " = " << formatNumber(result) << endl;
            cout << "DOKOŃCZYĆ KODOWANIE" << endl;
            waitEnter();
            break;
        }

        case 6: {//Pierwiastkowanie
            clearout();
            cout << "Root" << endl;
            long double a = 0.0L, n = 2.0L;
            long double result = 0.0L;
            cout << "Input a: "; cin >> a;
            cout << "N of root: "; cin >> n;
            result = powl(a, 1.0L / n);
            cout << formatNumber(n) << " root of " << formatNumber(a) << " = " << formatNumber(result) << endl;
            cout << "DOKOŃCZYĆ KODOWANIE" << endl;
            waitEnter();
            break;
        }

        case 7:{//Pi
            clearout();
            cout << "Pi constant" << endl;
            long double Pi = 3.14L;//tu dodać obliczenie pi
            cout<< "Pi = "<< Pi << endl;
            cout << "DOKOŃCZYĆ KODOWANIE" << endl;
            waitEnter();
            break;
        }

        case 8:{//E
            clearout();
            cout << "Euler's number" << endl;
            long double E = 2.71L;//tu dodać obliczenie e
            cout<< "e = "<< E << endl;
            cout << "DOKOŃCZYĆ KODOWANIE" << endl;
            waitEnter();
            break;
        }

        case 9: {//Sinus
            clearout();
            cout << "Sine" << endl;
            long double opposite = 0.0L, hypotenuse = 0.0L;
            long double result = 0.0L;
            cout << "Input Opposite: "; cin >> opposite; // przeciwległy bok
            cout << "Input Hypotenuse: "; cin >> hypotenuse; // przeciwprostokątna
            if (fabsl(hypotenuse) < 1e-18L) {//sprawdzamy czy nie dzielimy przez 0
                cout << "Error: hypotenuse cannot be zero." << endl;
            } else {
                result = opposite / hypotenuse;
                cout << "sin = " << formatNumber(result) << endl;
                cout << "DOKOŃCZYĆ KODOWANIE" << endl;
            }
            waitEnter();
            break;
        }

        case 10: {//Cosinus
            clearout();
            cout << "Cosine" << endl;
            long double adjacent = 0.0L, hypotenuse = 0.0L;
            long double result = 0.0L;
            cout << "Input Adjacent: "; cin >> adjacent; // bok przyległy
            cout << "Input Hypotenuse: "; cin >> hypotenuse; // przeciwprostokątna
            if (fabsl(hypotenuse) < 1e-18L) {//sprawdzamy czy nie dzielimy przez 0
                cout << "Error: hypotenuse cannot be zero." << endl;
            } else {
                result = adjacent / hypotenuse;
                cout << "cos = " << formatNumber(result) << endl;
                cout << "DOKOŃCZYĆ KODOWANIE" << endl;
            }
            waitEnter();
            break;
        }

        case 11: {//Tangens
            clearout();
            cout << "Tangent" << endl;
            long double opposite = 0.0L, adjacent = 0.0L;
            long double result = 0.0L;
            cout << "Input Opposite: "; cin >> opposite; // przeciwległy bok
            cout << "Input Adjacent: "; cin >> adjacent; // bok przyległy
            if (fabsl(adjacent) < 1e-18L) {//sprawdzamy czy nie dzielimy przez 0
                cout << "Error: adjacent cannot be zero." << endl;
            } else {
                result = opposite / adjacent;
                cout << "tan = " << formatNumber(result) << endl;
                cout << "DOKOŃCZYĆ KODOWANIE" << endl;
            }
            waitEnter();
            break;
        }

        case 12: {//Cotangens
            clearout();
            cout << "Cotangent" << endl;
            long double adjacent = 0.0L, opposite = 0.0L;
            long double result = 0.0L;
            cout << "Input Adjacent: "; cin >> adjacent; // bok przyległy
            cout << "Input Opposite: "; cin >> opposite; // przeciwległy bok
            if (fabsl(opposite) < 1e-18L) {//sprawdzanie czy nie dzielimy przez 0
                cout << "Error: opposite cannot be zero." << endl;
            } else {
                result = adjacent / opposite;
                cout << "cot = " << formatNumber(result) << endl;
                cout << "DOKOŃCZYĆ KODOWANIE" << endl;
            }
            waitEnter();
            break;
        }

        default://Nieznany wybór
            clearout();
            cout << "ERROR!" << endl;
            cout << "Unknown choice. Input 0-12." << endl;
            waitEnter();
            break;
        }

    }
    return 0;
}

