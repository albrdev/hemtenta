#include <iostream>
#include "fraction.hpp"

using namespace std;

void testOps(fraction F, fraction G) {
    // Test +
    F.print(); cout << " + "; G.print();
    cout << " = "; (F+G).print(); cout << endl;

    // Test -
    F.print(); cout << " - "; G.print();
    cout << " = "; (F - G).print(); cout << endl;

    // Test *
    F.print(); cout << " * "; G.print();
    cout << " = "; (F*G).print(); cout << endl;

    // Test /
    F.print(); cout << " / "; G.print();
    cout << " = "; (F/G).print(); cout << endl;

    // Test unary -
    cout << " - "; F.print();
    cout << " = "; (-F).print(); cout << endl;
}

int main(void) {
    testOps(fraction(4, 8), fraction(2, 3));

    return 0;
}
