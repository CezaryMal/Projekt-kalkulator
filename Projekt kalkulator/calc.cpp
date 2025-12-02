// calc.cpp
#include "calc.h"
#include <stdexcept>

// ---------------------- PODSTAWOWE FUNKCJE ----------------------

// Wartość bezwzględna
long double myAbs(long double x) {
    return (x < 0) ? -x : x;
}

// Pierwiastek kwadratowy metodą Newtona (Herona)
// Iteracyjnie poprawiamy przybliżenie pierwiastka.
// Brak pierwiastka z liczby ujemnej.
long double mySqrt(long double value) {
    if (value < 0) throw std::runtime_error("sqrt of negative");
    if (value == 0) return 0; //pierwiastek z 0 to 0

    long double x = value;
    for (int i = 0; i < 50; i++) {
        x = 0.5L * (x + value / x); //iteracja Newtona
    }
    return x;
}

// Potęgowanie dla całkowitych wykładników (szybkie potęgowanie)
// Obsługa dodatnich i ujemnych wykładników.
long double myPowInt(long double base, long long exp) {
    if (exp == 0) return 1.0L; // każda liczba do potęgi 0 to 1
    if (base == 0 && exp <= 0) throw std::runtime_error("0 cannot be raised to non-positive exponent");

    if (exp < 0) return 1.0L / myPowInt(base, -exp); //obsługa ujemnych wykładników

    long double result = 1.0L;
    while (exp > 0) {
        if (exp % 2 == 1) result *= base; //jeśli bit = 1, mnożymy przez bazę
        base *= base; //podnosimy bazę do kwadratu
        exp /= 2; //przesuwamy wykładnik w prawo
    }
    return result;
}

// ---------------------- OPERACJE PODSTAWOWE ----------------------

long double add(long double a, long double b) { return a + b; }
long double subtract(long double a, long double b) { return a - b; }
long double multiply(long double a, long double b) { return a * b; }

long double divide(long double a, long double b) {
    if (myAbs(b) < 1e-18L) throw std::runtime_error("division by zero");
    return a / b;
}

long double power(long double base, long double exponent) {
    // dla całkowitych wykładników używamy własnej funkcji
    if (exponent == (long long)exponent) {
        return myPowInt(base, (long long)exponent);
    }
    // dla rzeczywistych można użyć przybliżenia przez e^(exp * ln(base))
    // ale tu zostawiamy prostą wersję dla całkowitych
    throw std::runtime_error("non-integer exponent not supported");
}

long double root(long double value, long double n) {
    if (myAbs(n) < 1e-18L) throw std::runtime_error("root degree cannot be zero");
    if (n <= 0) throw std::runtime_error("root degree must be positive");

    long long nInt = (long long)n;
    if (value < 0 && nInt % 2 == 0) throw std::runtime_error("cannot take even root of negative");

    return myPowInt(value, 1 / nInt);
}

// ---------------------- TRYGO ----------------------
// Funkcje trygonometryczne w wersji geometrycznej (stosunki boków)

// Sinus = przeciwległa / przeciwprostokątna
long double sine(long double opposite, long double hypotenuse) {
    if (myAbs(hypotenuse) < 1e-18L) throw std::runtime_error("hypotenuse cannot be zero");
    if (opposite < 0 || hypotenuse <= 0) throw std::runtime_error("triangle sides must be positive");
    return opposite / hypotenuse;
}

// Cosinus = przyległa / przeciwprostokątna
long double cosine(long double adjacent, long double hypotenuse) {
    if (myAbs(hypotenuse) < 1e-18L) throw std::runtime_error("hypotenuse cannot be zero");
    if (adjacent < 0 || hypotenuse <= 0) throw std::runtime_error("triangle sides must be positive");
    return adjacent / hypotenuse;
}

// Tangens = przeciwległa / przyległa
long double tangent(long double opposite, long double adjacent) {
    if (myAbs(adjacent) < 1e-18L) throw std::runtime_error("adjacent cannot be zero");
    if (opposite < 0 || adjacent <= 0) throw std::runtime_error("triangle sides must be positive");
    return opposite / adjacent;
}

// Cotangens = przyległa / przeciwległa
long double cotangent(long double adjacent, long double opposite) {
    if (myAbs(opposite) < 1e-18L) throw std::runtime_error("opposite cannot be zero");
    if (adjacent < 0 || opposite <= 0) throw std::runtime_error("triangle sides must be positive");
    return adjacent / opposite;
}

// ---------------------- STAŁE MATEMATYCZNE ----------------------

// Przybliżenie liczby pi przez szereg Eulera
long double piConst() {
    const int N = 1000000; // liczba wyrazów sumy
    if (N <= 0) throw std::runtime_error("series length must be positive");

    long double sum = 0.0;
    for (int n = 1; n <= N; n++) {
        sum += 1.0L / (n * (long double)n);
    }
    return mySqrt(6.0L * sum);
}

// Przybliżenie liczby e przez szereg 1/n!
long double eConst() {
    const int TERMS = 30; // liczba wyrazów szeregu
    if (TERMS <= 0) throw std::runtime_error("series length must be positive");

    long double sum = 1.0L;
    long double term = 1.0L;
    for (int n = 1; n < TERMS; n++) {
        term /= n;   // kolejne wyrazy szeregu 1/n!
        sum += term; // dodajemy do sumy
    }
    return sum;
}