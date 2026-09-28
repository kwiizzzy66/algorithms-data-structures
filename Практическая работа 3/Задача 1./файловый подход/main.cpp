#include <iostream>
#include "gipo.h"
using namespace std;

int main() {
    double a, b;
    cin >> a;
    cin >> b;
    double c = gipo(a, b);
    cout << "Гипотенуза = " << c;
    return 0;
}
