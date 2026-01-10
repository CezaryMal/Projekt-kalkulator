/*
 Console Calculator – Project

 Group D2
*/

#include <iostream>
#include <chrono>
#include <thread>
#include <string>
#include <cctype>
#include <cmath>

#include "ui_format.h"
#include "calc.h"

using namespace std;

int main()
{
    while (true)
    {
        // --- MENU ---
        showmenu(
        {
            {1, "Addition"},
            {2, "Substraction"},
            {3, "Multiplication"},
            {4, "Division"},
            {5, "Exponentiation"},
            {6, "Root"},
            {7, "Pi"},
            {8, "Euler number"},
            {9, "Sine"},
            {10, "Cosine"},
            {11, "Tangent"},
            {12, "Cotangent"},
            {13, "Demo"},
            {14, "About"},
            {0, "Exit"}
        },
        "Console Calculator");

        // --- BEZPIECZNY ODCZYT WYBORU ---
        string c;
        cout << "Your choice: ";
        cin >> c;
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');



        bool ok = true;

        if (c.empty()) ok = false;
        for (char ch : c)
            if (!isdigit((unsigned char)ch))
                ok = false;

        if (!ok)
        {


            cout << "\nWrong option. Use menu numbers only.\n";
            waitEnter();
            continue;
        }

        int opt = stoi(c);

        // --- OBSLUGA WYBORU ---
        switch (opt)
        {
        case 0:
            return 0;

        // ---------- 1 ----------
        case 1: {
            long double a = readsafecheck("Input a: ");
            long double b = readsafecheck("Input b: ");
            resultTable("ADDITION", "a", a, "b", b, "RESULT", add(a,b));
            waitEnter();
            break;
        }

        // ---------- 2 ----------
        case 2: {
            long double a = readsafecheck("Input a: ");
            long double b = readsafecheck("Input b: ");
            resultTable("SUBSTRACTION", "a", a, "b", b, "RESULT", subtract(a,b));
            waitEnter();
            break;
        }

        // ---------- 3 ----------
        case 3: {
            long double a = readsafecheck("Input a: ");
            long double b = readsafecheck("Input b: ");
            resultTable("MULTIPLICATION", "a", a, "b", b, "RESULT", multiply(a,b));
            waitEnter();
            break;
        }

        // ---------- 4 ----------
        case 4: {
            long double a = readsafecheck("Input a: ");
            long double b = readsafecheck("Input b: ");

            try {
                resultTable("DIVISION", "a", a, "b", b, "RESULT", divide(a,b));
            } catch (const exception& e) {
                cout << "Error: " << e.what() << endl;
            }

            waitEnter();
            break;
        }

        // ---------- 5 ----------
        case 5: {
            long double a = readsafecheck("Input a: ");
            long double b = readsafecheck("Power: ");
            resultTable("POWER", "a", a, "b", b, "RESULT", power(a,b));
            waitEnter();
            break;
        }

        // ---------- 6 ----------
        case 6: {
            long double a = readsafecheck("Input a: ");
            long double n = readsafecheck("Root degree: ");

            try {
                resultTable("ROOT", "a", a, "n", n, "RESULT", root(a,n));
            } catch (const exception& e) {
                cout << "Error: " << e.what() << endl;
            }

            waitEnter();
            break;
        }

        // ---------- 7 ----------
        case 7:
            resultTable("PI", "pi", piConst());
            waitEnter();
            break;

        // ---------- 8 ----------
        case 8:
            resultTable("E", "e", eConst());
            waitEnter();
            break;

        // ---------- 9 ----------
        case 9: {
            long double a = readsafecheck("Opposite: ");
            long double b = readsafecheck("Hypotenuse: ");

            try {
                resultTable("SINE", "a", a, "b", b, "RESULT", sine(a,b));
            } catch (const exception& e) {
                cout << "Error: " << e.what() << endl;
            }

            waitEnter();
            break;
        }

        // ---------- 10 ----------
        case 10: {
            long double a = readsafecheck("Adjacent: ");
            long double b = readsafecheck("Hypotenuse: ");

            try {
                resultTable("COSINE", "a", a, "b", b, "RESULT", cosine(a,b));
            } catch (const exception& e) {
                cout << "Error: " << e.what() << endl;
            }

            waitEnter();
            break;
        }

        // ---------- 11 ----------
        case 11: {
            long double a = readsafecheck("Opposite: ");
            long double b = readsafecheck("Adjacent: ");

            try {
                resultTable("TANGENT", "a", a, "b", b, "RESULT", tangent(a,b));
            } catch (const exception& e) {
                cout << "Error: " << e.what() << endl;
            }

            waitEnter();
            break;
        }

        // ---------- 12 ----------
        case 12: {
            long double a = readsafecheck("Adjacent: ");
            long double b = readsafecheck("Opposite: ");

            try {
                resultTable("COTANGENT", "a", a, "b", b, "RESULT", cotangent(a,b));
            } catch (const exception& e) {
                cout << "Error: " << e.what() << endl;
            }

            waitEnter();
            break;
        }

        // ---------- 13 ----------
       case 13: {
    long double a = readsafecheck("Input a: ");
    long double b = readsafecheck("Input b: ");

    cout << "\nDemo:\n";
    cout << "add: " << formatNumber(add(a,b)) << endl;
    cout << "sub: " << formatNumber(subtract(a,b)) << endl;
    cout << "mul: " << formatNumber(multiply(a,b)) << endl;

    if (fabsl(b) < 1e-18)
        cout << "div: ERROR (division by zero)\n";
    else
        cout << "div: " << formatNumber(divide(a,b)) << endl;

    cout << "pow: " << formatNumber(power(a,b)) << endl;

    waitEnter();
    break;
}

        // ---------- 14 ----------
        case 14:
            clearout();
            showAbout();
            break;

        default:
            cout << "\nUnknown option.\n";
            waitEnter();
            break;
        }
    }
}
