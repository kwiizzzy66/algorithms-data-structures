#include <iostream>
#include <cmath>
using namespace std;

double gipo(int a, int b) {
    double c;
    c = sqrt(a * a + b * b);
    return c;
}

int main() {
    int a, b;
    cin >> a;
    cin >> b;
    
    double c = gipo(a, b);
    
    cout << "Гипотенуза = " << c;
    return 0;
}
