#include <iostream>

using namespace std;

class fraction {
  private:
    int numer, denom;
    static int GCD(int a, int b) {
        if(b == 0) return a;
        return GCD(b, a % b);
    }
  public:
    fraction() { denom = 1; numer = 1; }
    fraction(int N, int D) {
        int G = GCD(N, D);
        numer = N/G; denom = D/G;
        if(denom < 0) { denom = -denom; numer = -numer; }
    }
    fraction operator+(fraction F) {
        int N = numer*F.denom + denom*F.numer;
        int D = denom*F.denom;
        return fraction(N, D);
    }
    fraction operator*(fraction F) {
        int N = numer*F.numer;
        int D = denom*F.denom;
        return fraction(N, D);
    }
    fraction operator-() {
        return fraction(-numer, denom);
    }
    fraction inv() {
        return fraction(denom, numer);
    }
    void print() {
        cout << numer << "/" << denom;
    }
};

void testOps(fraction F, fraction G) {
    // Test +
    F.print(); cout << " + "; G.print();
    cout << " = "; (F+G).print(); cout << endl;

    // Test *
    F.print(); cout << " * "; G.print();
    cout << " = "; (F*G).print(); cout << endl;

    // Test unary -
    cout << " - "; F.print();
    cout << " = "; (-F).print(); cout << endl;
}

int main(void) {
    testOps(fraction(4, 8), fraction(2, 3));
 
    return 0;
}