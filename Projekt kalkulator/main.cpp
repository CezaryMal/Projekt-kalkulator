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

using namespace std;


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
	//setlocale(LC_ALL, "");//Ustawienie lokalizacji na polską żeby obsługiwać polskie znaki
    while (true) {// Pętla do ciągłego działania programu
        clearout(); // czyścimy ekran przed pokazaniem menu
        showmenu(); // wyświetlamy menu
        string choice;
        cout << "Input your choice: ";
        cin >> choice; // czytamy wybór użytkownika jako tekst (pozwala na 10,11,12)

        int opt = -1;
        // Parsowanie wyboru: akceptujemy wielocyfrowe liczby (np. 10, 11, 12).
        bool ok = true;
        if (choice.empty()) ok = false;
        for (char ch : choice) if (!isdigit(static_cast<unsigned char>(ch))) ok = false;
        if (!ok) {
            // Nieprawidłowy format wyboru (np. litery) — prosimy o ponowny wybór
            cout << "Unknown choice. Input 0-12." << endl;
            waitEnter();
            continue;
        }
        try {
            opt = stoi(choice); // konwersja na int
        } catch (...) {
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

        case 1:
        case 2:
        case 3:
        case 4: {
            long double a = 0.0L, b = 0.0L;
            long double result = 0.0L;
            cout << "Input a: "; cin >> a;
            cout << "Input b: "; cin >> b;
            switch (opt) {
            case 1://Dodawanie
                cout << "DOKOŃCZYĆ KODOWANIE" << endl;
                result = a + b;
                cout << result;
                break;
            case 2://Odejmowanie
                cout << "DOKOŃCZYĆ KODOWANIE" << endl;
                cout << result;
                break;
            case 3://Mnożenie
                cout << "DOKOŃCZYĆ KODOWANIE" << endl;
                cout << result;
                break;
            case 4://Dzielenie
                // Dzielenie: sprawdzamy czy nie dzielimy przez zero, jeśli OK obliczamy wynik
                if (fabsl(b) < 1e-18L) {
                    // b (mianownik) jest praktycznie zerem -> wyświetlamy błąd
                    cout << "Error: division by zero is not allowed." << endl;
                } else {
                    cout << "DOKOŃCZYĆ KODOWANIE" << endl;
                    waitEnter();
                }
                break;
            }
            waitEnter();
            break;
        }

        case 5: {//Potęgowanie
            long double a = 0.0L, b = 0.0L;
            cout << "Input a: "; cin >> a;
            cout << "To the power of: "; cin >> b;
            cout << "DOKOŃCZYĆ KODOWANIE" << endl;
            waitEnter();
            break;
        }

        case 6: {//Pierwiastkowanie
            long double a = 0.0L, n = 2.0L;
            cout << "Input a: "; cin >> a;
            cout << "N of root: "; cin >> n;
            cout << "DOKOŃCZYĆ KODOWANIE" << endl;
            waitEnter();
            break;
        }

        case 7://Pi
            cout << "DOKOŃCZYĆ KODOWANIE" << endl;
            waitEnter();
            break;

        case 8://E
            cout << "DOKOŃCZYĆ KODOWANIE" << endl;
            waitEnter();
            break;

        case 9: {//Sinus
            long double opposite = 0.0L, hypotenuse = 0.0L;
            cout << "Input Opposite: "; cin >> opposite; // przeciwległy bok
            cout << "Input Hypotenuse: "; cin >> hypotenuse; // przeciwprostokątna
            if (fabsl(hypotenuse) < 1e-18L) {//sprawdzamy czy nie dzielimy przez 0
                cout << "Error: hypotenuse cannot be zero." << endl;
            } else {
                cout << "DOKOŃCZYĆ KODOWANIE" << endl;
            }
            waitEnter();
            break;
        }

        case 10: {//Cosinus
            long double adjacent = 0.0L, hypotenuse = 0.0L;
            cout << "Input Adjacent: "; cin >> adjacent; // bok przyległy
            cout << "Input Hypotenuse: "; cin >> hypotenuse; // przeciwprostokątna
            if (fabsl(hypotenuse) < 1e-18L) {//sprawdzamy czy nie dzielimy przez 0
                cout << "Error: hypotenuse cannot be zero." << endl;
            } else {
                cout << "DOKOŃCZYĆ KODOWANIE" << endl;
            }
            waitEnter();
            break;
        }

        case 11: {//Tangens
            long double opposite = 0.0L, adjacent = 0.0L;
            cout << "Input Opposite: "; cin >> opposite; // przeciwległy bok
            cout << "Input Adjacent: "; cin >> adjacent; // bok przyległy
            if (fabsl(adjacent) < 1e-18L) {//sprawdzamy czy nie dzielimy przez 0
                cout << "Error: adjacent cannot be zero." << endl;
            } else {
                cout << "DOKOŃCZYĆ KODOWANIE" << endl;
            }
            waitEnter();
            break;
        }

        case 12: {//Cotangens
            long double adjacent = 0.0L, opposite = 0.0L;
            cout << "Input Adjacent: "; cin >> adjacent; // bok przyległy
            cout << "Input Opposite: "; cin >> opposite; // przeciwległy bok
            if (fabsl(opposite) < 1e-18L) {//sprawdzanie czy nie dzielimy przez 0
                cout << "Error: opposite cannot be zero." << endl;
            } else {
                cout << "DOKOŃCZYĆ KODOWANIE" << endl;
            }
            waitEnter();
            break;
        }

        default://Nieznany wybór
            cout << "Unknown choice. Input 0-12." << endl;
            waitEnter();
            break;
        }

    }
    return 0;
}

