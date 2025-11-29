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
#include <clocale>
#include "ui_format.h"
#include "calc.h"



using namespace std;


int main() {
    cout << fixed; // Ustawienie precyzji wyświetlania liczb zmiennoprzecinkowych
	setlocale(LC_ALL, "");//Ustawienie lokalizacji na polską żeby obsługiwać polskie znaki
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

        case 1:{//Dodawanie
            clearout();
            showmenu({{"input a + input b"}},"Addition");
            long double a = 0.0L, b = 0.0L;
            long double result = 0.0L;
            cout << "Input a: "; cin >> a;
            cout << "Input b: "; cin >> b;
            result = a + b;
            cout << formatNumber(a) << " + " << formatNumber(b) << " = " << formatNumber(result) << endl;
            waitEnter();
            break;
        }
        case 2:{//Odejmowanie
            clearout();
            showmenu({{"input a - input b"}},"Substraction");
            long double a = 0.0L, b = 0.0L;
            long double result = 0.0L;
            cout << "Input a: "; cin >> a;
            cout << "Input b: "; cin >> b;
            result = a - b;
            cout << formatNumber(a) << " - " << formatNumber(b) << " = " << formatNumber(result) << endl;
            waitEnter();
            break;
        }
        case 3:{//Mnożenie
            clearout();
            showmenu({{"input a * input b"}},"Multiplication");
            long double a = 0.0L, b = 0.0L;
            long double result = 0.0L;
            cout << "Input a: "; cin >> a;
            cout << "Input b: "; cin >> b;
            result = a * b;
            cout << formatNumber(a) << " * " << formatNumber(b) << " = " << formatNumber(result) << endl;//wyświetlanie wyniku
            waitEnter();
            break;
        }
        case 4: { // Dzielenie: sprawdzamy czy nie dzielimy przez zero, jeśli OK obliczamy wynik
            clearout();
            showmenu({{"input a / input b"}},"Division");
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
                waitEnter();
            }
            break;
        }

        case 5: {//Potęgowanie
            clearout();
            showmenu({{"input a ^ input b"}},"Exponentiation");
            long double a = 0.0L, b = 0.0L;
            long double result = 0.0L;
            cout << "Input a: "; cin >> a;
            cout << "To the power of: "; cin >> b;
            result = powl(a, b);
            cout << formatNumber(a) << " ^ " << formatNumber(b) << " = " << formatNumber(result) << endl;
            waitEnter();
            break;
        }

        case 6: {//Pierwiastkowanie
            clearout();
            showmenu({{"input n root of input a"}},"Root");
            long double a = 0.0L, n = 2.0L;
            long double result = 0.0L;
            cout << "Input a: "; cin >> a;
            cout << "N of root: "; cin >> n;
            result = powl(a, 1.0L / n);
            cout << formatNumber(n) << " root of " << formatNumber(a) << " = " << formatNumber(result) << endl;
            waitEnter();
            break;
        }

        case 7:{//Pi
            clearout();
            showmenu({{"Pi constant"}},"Pi constant");
            cout<< "Pi = "<< piConst() << endl;
            waitEnter();
            break;
        }

        case 8:{//E
            clearout();
            showmenu({{"Euler's number"}},"Euler's number");
            cout<< "e = "<< eConst() << endl;
            waitEnter();
            break;
        }

        case 9: {//Sinus
            clearout();
            showmenu({{"input opposite / input hypotenuse"}},"Sine");
            long double opposite = 0.0L, hypotenuse = 0.0L;
            long double result = 0.0L;
            cout << "Input Opposite: "; cin >> opposite; // przeciwległy bok
            cout << "Input Hypotenuse: "; cin >> hypotenuse; // przeciwprostokątna
            if (fabsl(hypotenuse) < 1e-18L) {//sprawdzamy czy nie dzielimy przez 0
                cout << "Error: hypotenuse cannot be zero." << endl;
            } else {
                result = opposite / hypotenuse;
                cout << "sin = " << formatNumber(result) << endl;
            }
            waitEnter();
            break;
        }

        case 10: {//Cosinus
            clearout();
            showmenu({{"input adjacent / input hypotenuse"}},"Cosine");
            long double adjacent = 0.0L, hypotenuse = 0.0L;
            long double result = 0.0L;
            cout << "Input Adjacent: "; cin >> adjacent; // bok przyległy
            cout << "Input Hypotenuse: "; cin >> hypotenuse; // przeciwprostokątna
            if (fabsl(hypotenuse) < 1e-18L) {//sprawdzamy czy nie dzielimy przez 0
                cout << "Error: hypotenuse cannot be zero." << endl;
            } else {
                result = adjacent / hypotenuse;
                cout << "cos = " << formatNumber(result) << endl;
            }
            waitEnter();
            break;
        }

        case 11: {//Tangens
            clearout();
            showmenu({{"input opposite / input adjacent"}},"Tangent");
            long double opposite = 0.0L, adjacent = 0.0L;
            long double result = 0.0L;
            cout << "Input Opposite: "; cin >> opposite; // przeciwległy bok
            cout << "Input Adjacent: "; cin >> adjacent; // bok przyległy
            if (fabsl(adjacent) < 1e-18L) {//sprawdzamy czy nie dzielimy przez 0
                cout << "Error: adjacent cannot be zero." << endl;
            } else {
                result = opposite / adjacent;
                cout << "tan = " << formatNumber(result) << endl;
            }
            waitEnter();
            break;
        }

        case 12: {//Cotangens
            clearout();
            showmenu({{"input adjacent / input opposite"}},"Cotangent");
            long double adjacent = 0.0L, opposite = 0.0L;
            long double result = 0.0L;
            cout << "Input Adjacent: "; cin >> adjacent; // bok przyległy
            cout << "Input Opposite: "; cin >> opposite; // przeciwległy bok
            if (fabsl(opposite) < 1e-18L) {//sprawdzanie czy nie dzielimy przez 0
                cout << "Error: opposite cannot be zero." << endl;
            } else {
                result = adjacent / opposite;
                cout << "cot = " << formatNumber(result) << endl;
            }
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

