// calc.cpp
#include "calc.h"
#include <cmath>
#include <stdexcept>

// Dodaje dwie liczby przekazane jako argumenty
long double add(long double a, long double b) { return a + b; }
// Odejmuje druga liczbe od pierwszej
long double subtract(long double a, long double b) { return a - b; }
// Mnozy dwie wartosci
long double multiply(long double a, long double b) { return a * b; }

// Dzieli liczbe a przez b i rzuca wyjatek przy probie dzielenia przez zero
long double divide(long double a, long double b) {
    if (fabsl(b) < 1e-18L) throw std::runtime_error("division by zero");
    return a / b;
}

// Podnosi podstawe do podanego wykladnika
long double power(long double base, long double exponent) { return powl(base, exponent); }

// Liczy pierwiastek n-tego stopnia, pilnujac aby stopien nie byl zerem
long double root(long double value, long double n) {
    if (fabsl(n) < 1e-18L) throw std::runtime_error("root base cannot be zero");
    return powl(value, 1.0L / n);
}

// Zwraca sinus jako stosunek przeciwleglej do przeciwprostokatnej
long double sine(long double opposite, long double hypotenuse) {
    if (fabsl(hypotenuse) < 1e-18L) throw std::runtime_error("hypotenuse cannot be zero");
    return opposite / hypotenuse;
}

// Zwraca cosinus jako stosunek przyleglej do przeciwprostokatnej
long double cosine(long double adjacent, long double hypotenuse) {
    if (fabsl(hypotenuse) < 1e-18L) throw std::runtime_error("hypotenuse cannot be zero");
    return adjacent / hypotenuse;
}

// Tangens to stosunek przeciwleglej do przyleglej
long double tangent(long double opposite, long double adjacent) {
    if (fabsl(adjacent) < 1e-18L) throw std::runtime_error("adjacent cannot be zero");
    return opposite / adjacent;
}

// Cotangens to odwrotnosc tangensa
long double cotangent(long double adjacent, long double opposite) {
    if (fabsl(opposite) < 1e-18L) throw std::runtime_error("opposite cannot be zero");
    return adjacent / opposite;
}

// Zwraca wartosc stalej Pi korzystajac z funkcji acos
// !!PRZEROBIĆ NA LICZENIE RĘCZNE NIE Z GOTOWCA
long double piConst() {
    
    return acosl(-1.0L);
}
// Zwraca wartosc stalej e
// Aproksymacja ln(x) przez szereg Taylora wokół 1
long double myLn(long double x) {
    if (x <= 0) return 0; // ln(x) niezdefiniowane dla x <= 0
    long double y = (x - 1) / (x + 1); 
    long double y2 = y * y;
    long double result = 0.0;
    long double term = y;
    int n = 1;

    // rozwinięcie w szereg (metoda logarytmu przez arctanh)
    while (n < 1000) {
        result += term / n;
        term *= y2;
        n += 2;
    }
    return 2 * result;
}

// Funkcja zwracająca stałą e
long double eConst() {
    // Szukamy x takiego, że ln(x) = 1
    long double x = 2.7; // punkt startowy
    for (int i = 0; i < 50; i++) {
        long double fx = myLn(x) - 1.0;
        long double dfx = 1.0 / x; // pochodna ln(x)
        x = x - fx / dfx; // Newton-Raphson
    }
    return x;
}
