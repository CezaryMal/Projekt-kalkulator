// calc.h
#pragma once
// Zwraca sume dwoch liczb
long double add(long double a, long double b);
// Odejmuje druga liczbe od pierwszej
long double subtract(long double a, long double b);
// Mnozy przekazane argumenty
long double multiply(long double a, long double b);
// Dzieli a przez b i pilnuje aby nie dzielic przez zero
long double divide(long double a, long double b);
// Podnosi podstawe do wykladnika
long double power(long double base, long double exponent);
// Oblicza pierwiastek n-tego stopnia z wartosci
long double root(long double value, long double n);
// Zwraca sinus jako stosunek przeciwleglej do przeciwprostokatnej
long double sine(long double opposite, long double hypotenuse);
// Zwraca cosinus jako stosunek przyprostokatnej do przeciwprostokatnej
long double cosine(long double adjacent, long double hypotenuse);
// Zwraca tangens jako stosunek przeciwleglej do przyleglej
long double tangent(long double opposite, long double adjacent);
// Zwraca cotangens jako stosunek przyleglej do przeciwleglej
long double cotangent(long double adjacent, long double opposite);
// Dostarcza stala Pi z biblioteki matematycznej
long double piConst();
// Dostarcza stala e
long double eConst();
