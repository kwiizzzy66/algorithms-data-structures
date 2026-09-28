#include <iostream>
#include <cmath>
using namespace std;

class Triangle {
    double a;
    double b;

public:
    Triangle(double cathetus_a, double cathetus_b) : 
        a(cathetus_a), b(cathetus_b) {  
        
        if (a <= 0 || b <= 0) {
            throw runtime_error("Катеты должны быть положительными!");
        }
    }
    
    double hypotenuse() const {
        return sqrt(a * a + b * b);
    }
};

int main() {
    try {
        cout << "Введите два положительных катета a и b через пробел:";
        double a, b;
        cin >> a >> b;

        Triangle t{a, b}; 

        cout << "Гипотенуза = " << t.hypotenuse() << endl;
    } catch(const exception& e) {
        cerr << "Ошибка! " << e.what() << endl;
    }

    return 0;
}
