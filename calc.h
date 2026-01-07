// calc.h
#ifndef CALC_H
#define CALC_H

// ---------------------- PODSTAWOWE FUNKCJE ----------------------

// Wartość bezwzględna
long double myAbs(long double x);

// Pierwiastek kwadratowy metodą Newtona (Herona)
long double mySqrt(long double value);

// Potęgowanie dla całkowitych wykładników
long double myPowInt(long double base, long long exp);

// ---------------------- OPERACJE PODSTAWOWE ----------------------

long double add(long double a, long double b);
long double subtract(long double a, long double b);
long double multiply(long double a, long double b);
long double divide(long double a, long double b);

long double power(long double base, long double exponent);
long double root(long double value, long double n);

// ---------------------- TRYGO ----------------------

long double sine(long double opposite, long double hypotenuse);
long double cosine(long double adjacent, long double hypotenuse);
long double tangent(long double opposite, long double adjacent);
long double cotangent(long double adjacent, long double opposite);

// ---------------------- STAŁE MATEMATYCZNE ----------------------

long double piConst();   // przybliżenie liczby pi
long double eConst();    // przybliżenie liczby e

#endif // CALC_H
