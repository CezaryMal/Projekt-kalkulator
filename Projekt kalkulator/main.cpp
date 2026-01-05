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
                {13, "Demo of all functions"},
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
            long double a = readsafecheck("Input a: ");
            long double b = readsafecheck("Input b: ");
            long double result = 0.0L;
            result = add(a, b);
            cout << formatNumber(a) << " + " << formatNumber(b)
             << " = " << formatNumber(result) << endl;
            waitEnter();
            break;
        }

        case 2:{//Odejmowanie
            clearout();
            showmenu({{"input a - input b"}},"Substraction");
            long double a = readsafecheck("Input a: ");
            long double b = readsafecheck("Input b: ");
            long double result = 0.0L;
            result = subtract(a, b);
            cout << formatNumber(a) << " - " << formatNumber(b)
             << " = " << formatNumber(result) << endl;
            waitEnter();
            break;
        }
        case 3:{//Mnożenie
            clearout();
            showmenu({{"input a * input b"}},"Multiplication");
            long double result = 0.0L;
            long double a = readsafecheck("Input a: ");
            long double b = readsafecheck("Input b: ");
            result = multiply(a, b);
            cout << formatNumber(a) << " * " << formatNumber(b)
             << " = " << formatNumber(result) << endl;//wyświetlanie wyniku
            waitEnter();
            break;
        }

        case 4: { // Dzielenie: sprawdzamy czy nie dzielimy przez zero, jeśli OK obliczamy wynik
            clearout();
            showmenu({{"input a / input b"}},"Division");
            long double a = readsafecheck("Input a: ");
            long double b = readsafecheck("Input b: ");
            long double result = 0.0L;

            try {
                result = divide(a, b);
                cout << formatNumber(a) << " / " << formatNumber(b) << " = " << formatNumber(result) << endl;
            } catch (const std::runtime_error& e) {
                cout << "Error: " << e.what() << endl;
            }
            
            waitEnter();
            break;
        }

        case 5: {//Potęgowanie
            clearout();
            showmenu({{"input a ^ To the power of b"}},"Exponentiation");
            long double a = readsafecheck("Input a: ");
            long double b = readsafecheck("To the power of: ");
            long double result = 0.0L;

            try{
                result = power(a, b);
                cout << formatNumber(a) << " ^ " << formatNumber(b) << " = " << formatNumber(result) << endl;
            }
            catch(const std::exception& e) {
                cout << "Error: " << e.what() << endl;
            }
            waitEnter();
            break;
        }

        case 6: {//Pierwiastkowanie
            clearout();
            showmenu({{"input n root of input a"}},"Root");
            long double a = readsafecheck("Input a: ");
            long double b = readsafecheck("N of root: ");
            long double result = 0.0L;
            try {
                long double result = root(a, b);
                cout << formatNumber(b) << " root of " << formatNumber(a) << " = " << formatNumber(result) << endl;
            } catch (const std::runtime_error& e) {
                cout << "Error: " << e.what() << endl;
            }
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
            long double a = readsafecheck("Input opposite: "); // przeciwległy bok
            long double b = readsafecheck("Input Hypotenuse: "); // przeciwprostokątna
            long double result = 0.0L;

            try {
                result = sine(a, b);
                cout << "sin = " << formatNumber(result) << endl;
            } catch (const std::runtime_error& e) {
                cout << "Error: " << e.what() << endl;
            }
            waitEnter();
            break;
        }

        case 10: {//Cosinus
            clearout();
            showmenu({{"input adjacent / input hypotenuse"}},"Cosine");
            long double a = readsafecheck("Input adjacent: "); // bok przyległy
            long double b = readsafecheck("Input hypotenuse: "); // przeciwprostokątna
            long double result = 0.0L;

            try {
                result = cosine(a, b);
                cout << "cos = " << formatNumber(result) << endl;
            } catch (const std::runtime_error& e) {
                cout << "Error: " << e.what() << endl;
            }
            waitEnter();
            break;
        }

        case 11: {//Tangens
            clearout();
            showmenu({{"input opposite / input adjacent"}},"Tangent");
            long double a = readsafecheck("Input opposite: ");// przeciwległy bok
            long double b = readsafecheck("Input adjacent: ");// bok przyległy
            long double result = 0.0L;
            try {
                result = tangent(a, b);
                cout << "tan = " << formatNumber(result) << endl;
            } catch (const std::runtime_error& e) {
                cout << "Error: " << e.what() << endl;
            }
            waitEnter();
            break;
        }

        case 12: {//Cotangens
            clearout();
            showmenu({{"input adjacent / input opposite"}},"Cotangent");
            long double a = readsafecheck("Input adjacent: ");// bok przyległy
            long double b = readsafecheck("Input opposite: ");// przeciwległy bok
            long double result = 0.0L;

            try {
                result = cotangent(a, b);
                cout << "cot = " << formatNumber(result) << endl;
            } catch (const std::runtime_error& e) {
                cout << "Error: " << e.what() << endl;
            }
            waitEnter();
            break;
        }
        case 13: {
            clearout();
            showmenu({{"Demo of all functions"}},"Demo");
            long double a = readsafecheck("Input a: ");
            long double b = readsafecheck("Input b: ");
            if (myAbs(b) < 1e-18L) {//sprawdzanie czy nie dzielimy przez 0
                cout << "Error: b cannot be zero." << endl;
            } 
            else{
                border();
                cout << "Addition: " << formatNumber(add(a,b)) << endl;
                cout << "Substraction: " << formatNumber(subtract(a,b))<< endl;
                cout << "Multiplication: " << formatNumber(multiply(a,b))<< endl;
                cout << "Division: " << formatNumber(divide(a,b))<< endl;
                cout << "Exponentiation: " << formatNumber(power(a,b))<< endl;
                cout << "Root: " << formatNumber(root(a,b))<< endl;
                cout << "Pi: " << piConst()<< endl;
                cout << "E: " << eConst()<< endl;
                cout << "Sine: " << formatNumber(sine(a,b))<< endl;
                cout << "Cosine: " << formatNumber(cosine(a,b))<< endl;
                cout << "Tangent: " << formatNumber(tangent(a,b))<< endl;
                cout << "Cotangent: " << formatNumber(cotangent(a,b))<< endl;
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