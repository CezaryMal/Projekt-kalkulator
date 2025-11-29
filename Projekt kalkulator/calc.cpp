// calc.cpp
#include "calc.h"
#include <cmath>
#include <stdexcept>

long double add(long double a, long double b) { return a + b; }
long double subtract(long double a, long double b) { return a - b; }
long double multiply(long double a, long double b) { return a * b; }

long double divide(long double a, long double b) {
    if (fabsl(b) < 1e-18L) throw std::runtime_error("division by zero");
    return a / b;
}

long double power(long double base, long double exponent) { return powl(base, exponent); }

long double root(long double value, long double n) {
    if (fabsl(n) < 1e-18L) throw std::runtime_error("root base cannot be zero");
    return powl(value, 1.0L / n);
}

long double sine(long double opposite, long double hypotenuse) {
    if (fabsl(hypotenuse) < 1e-18L) throw std::runtime_error("hypotenuse cannot be zero");
    return opposite / hypotenuse;
}

// analogicznie cosine/tangent/cotangent...

long double piConst() { return acosl(-1.0L); }
long double eConst() { return expl(1.0L); }
