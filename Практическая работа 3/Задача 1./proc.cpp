#include <iostream>
#include <cmath>
using namespace std;

int main() {
    double a, b;
    cin >> a;
    cin >> b;
    double r = pow(a, 2);
    double d = pow(b, 2);
    double c = sqrt(r + d);
    cout << "Гипотенуза = " << c;
    return 0;
}
