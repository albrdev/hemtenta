#include <iostream>
#include "fraction.hpp"
#include <cstdio>

using namespace std;

int fraction::GCD(int a, int b) {
    if(b == 0) return a;
    return GCD(b, a % b);
}

fraction::fraction() { denom = 1; numer = 1; }

fraction::fraction(int N, int D) {
    int G = GCD(N, D);
    numer = N / G; denom = D / G;
    if(denom < 0) { denom = -denom; numer = -numer; }
}

fraction fraction::operator+(fraction F) {
    int N = numer * F.denom + denom * F.numer;
    int D = denom * F.denom;
    return fraction(N, D);
}

fraction fraction::operator-(fraction F) {
    int N = numer * F.denom - denom * F.numer;
    int D = denom * F.denom;
    return fraction(N, D);
}

fraction fraction::operator*(fraction F) {
    int N = numer * F.numer;
    int D = denom * F.denom;
    return fraction(N, D);
}

fraction fraction::operator/(fraction F) {
    return (*this) * F.inv();
}

fraction fraction::operator-() {
    return fraction(-numer, denom);
}

fraction fraction::inv() {
    return fraction(denom, numer);
}

void fraction::print() {
    cout << numer << "/" << denom;
}
