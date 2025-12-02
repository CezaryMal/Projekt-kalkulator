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
#include <iomanip>
#include <string>
#include <sstream>
#include <clocale>
#include "ui_format.h"
#include "calc.h"

using namespace std;

int main() {
    cout << fixed << setprecision(15); // Ustawienie precyzji wyświetlania liczb zmiennoprzecinkowych

    while (true) {// Pętla do ciągłego działania programu
        clearout(); // czyścimy ekran przed pokazaniem menu
        showmenu(
            {
                {1, "Addition"},
                {2, "Substraction"},
                {3, "Multiplication"},
                {4, "Division"},
                {5, "Exponentiation"},
                {6, "Root"},
                {7, "Pi constant"},
                {8, "Euler's number"},
                {9, "Sine"},
                {10, "Cosine"},
                {11, "Tangent"},
                {12, "Cotangent"},
                {0, "Exit"}
            },
            "Console Calculator"
        ); // wyświetlamy menu

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
            showmenu({{"Unknown choice. Input 0-12."}}, "Error");
            waitEnter();
            continue;
        }
        try {
            opt = stoi(choice); // konwersja na int
        } catch (...) {// obsługa wyjątków na wypadek bardzo dużych liczb
            showmenu({{"Unknown choice. Input 0-12."}}, "Error");
            waitEnter();
            continue;
        }

        // Główna instrukcja wyboru. Każdy case obsługuje jedną pozycję menu.
        switch (opt) {
        case 0:
            // Wyjście z programu: czyścimy ekran i kończymy działanie.
            clearout();
            showmenu({{"See you next time!"}}, "EXIT");
            this_thread::sleep_for(chrono::seconds(2));
            return 0;

        case 1: { // Dodawanie
            clearout();
            showmenu({{"input a + input b"}}, "Addition");
            long double a = 0.0L, b = 0.0L;
            cout << "Input a: "; cin >> a;
            cout << "Input b: "; cin >> b;
            cout << formatNumber(a) << " + " << formatNumber(b)
                 << " = " << formatNumber(add(a, b)) << endl;
            waitEnter();
            break;
        }

        case 2: { // Odejmowanie
            clearout();
            showmenu({{"input a - input b"}}, "Substraction");
            long double a = 0.0L, b = 0.0L;
            cout << "Input a: "; cin >> a;
            cout << "Input b: "; cin >> b;
            cout << formatNumber(a) << " - " << formatNumber(b)
                 << " = " << formatNumber(subtract(a, b)) << endl;
            waitEnter();
            break;
        }

        case 3: { // Mnożenie
            clearout();
            showmenu({{"input a * input b"}}, "Multiplication");
            long double a = 0.0L, b = 0.0L;
            cout << "Input a: "; cin >> a;
            cout << "Input b: "; cin >> b;
            cout << formatNumber(a) << " * " << formatNumber(b)
                 << " = " << formatNumber(multiply(a, b)) << endl;
            waitEnter();
            break;
        }

        case 4: { // Dzielenie
            clearout();
            showmenu({{"input a / input b"}}, "Division");
            long double a = 0.0L, b = 0.0L, result = 0.0L;
            cout << "Input a (numerator): "; cin >> a;
            cout << "Input b (denominator): "; cin >> b;

            if (myAbs(b) < 1e-18L) {
                // b (mianownik) jest praktycznie zerem -> wyświetlamy błąd
                cout << "Error: division by zero is not allowed." << endl;
            } 
            else {
                result = divide(a, b);
                cout << formatNumber(a) << " / " << formatNumber(b) << " = " << formatNumber(result) << endl;
            }
            
            waitEnter();
            break;
        }

        case 5: { // Potęgowanie
            clearout();
            showmenu({{"input a ^ input b"}}, "Exponentiation");
            long double a, b;
            cout << "Input a: "; cin >> a;
            cout << "To the power of: "; cin >> b;
            cout << formatNumber(a) << " ^ " << formatNumber(b) << " = " << formatNumber(power(a, b)) << endl;
            waitEnter();
            break;
        }

        case 6: { // Pierwiastkowanie
            clearout();
            showmenu({{"input n root of input a"}}, "Root");
            long double a = 0.0L, n = 2.0L;
            cout << "Input a: "; cin >> a;
            cout << "N of root: "; cin >> n;
            cout << formatNumber(n) << " root of " << formatNumber(a) << " = " << formatNumber(root(a, n)) << endl;
            waitEnter();
            break;
        }

        case 7: { // Stała pi
            clearout();
            showmenu({{"Pi constant"}}, "Pi constant");
            cout << "Pi = " << piConst() << endl;
            waitEnter();
            break;
        }

        case 8: { // Stała e
            clearout();
            showmenu({{"Euler's number"}}, "Euler's number");
            cout << "e = " << eConst() << endl;
            waitEnter();
            break;
        }

        case 9: { // Sinus
            clearout();
            showmenu({{"input opposite / input hypotenuse"}}, "Sine");
            long double opposite, hypotenuse;
            cout << "Input Opposite: "; cin >> opposite;
            cout << "Input Hypotenuse: "; cin >> hypotenuse;
            cout << formatNumber(opposite) << " root of " << formatNumber(hypotenuse) << " = " << formatNumber(sine(opposite, hypotenuse)) << endl;
            waitEnter();
            break;
        }

        case 10: { // Cosinus
            clearout();
            showmenu({{"input adjacent / input hypotenuse"}}, "Cosine");
            long double adjacent, hypotenuse;
            cout << "Input Adjacent: "; cin >> adjacent;
            cout << "Input Hypotenuse: "; cin >> hypotenuse;
            cout << formatNumber(adjacent) << " root of " << formatNumber(hypotenuse) << " = " << formatNumber(cosine(adjacent, hypotenuse)) << endl;
            waitEnter();
            break;
        }

        case 11: { // Tangens
            clearout();
            showmenu({{"input opposite / input adjacent"}}, "Tangent");
            long double opposite, adjacent;
            cout << "Input Opposite: "; cin >> opposite;
            cout << "Input Adjacent: "; cin >> adjacent;
            cout << formatNumber(opposite) << " root of " << formatNumber(adjacent) << " = " << formatNumber(cosine(opposite, adjacent)) << endl;
            waitEnter();
            break;
        }

        case 12: { // Cotangens
            clearout();
            showmenu({{"input adjacent / input opposite"}}, "Cotangent");
            long double adjacent, opposite;
            cout << "Input Adjacent: "; cin >> adjacent;
            cout << "Input Opposite: "; cin >> opposite;
            cout << formatNumber(adjacent) << " root of " << formatNumber(opposite) << " = " << formatNumber(cosine(adjacent, opposite)) << endl;
            waitEnter();
            break;
        }

        default://Nieznany wybór
            clearout();
            showmenu({{"Unknown choice. Input 0-12."}}, "Error");
            waitEnter();
            break;
        }

    }
    return 0;
}

