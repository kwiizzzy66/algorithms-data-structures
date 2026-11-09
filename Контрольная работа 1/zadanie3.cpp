// Вычисление значения выражения 4(3 - x) - 11 - 7(2x - 5)
// после упрощения: 36 - 18x

#include <iostream>
using namespace std;

// Функция вычисляет значение упрощённого выражения
// x — значение переменной, введённое пользователем
// Возвращает результат вычисления
double vi4isl(double x)
{
    const int FreeCoef = 36;
    const int Coef = 18;

    return FreeCoef - Coef*x;
} 


int main() 
{
// Блок ввода исходных данных
    double x = 0;
    cout << "Введите значение переменной х" << endl;
    cin >> x;
    
// Блок вывода результата 
    double result = vi4isl(x);
    cout << "Значение выражения 4(3 - x) - 11 - 7(2x - 5) = " << result << endl;
    return 0;
}