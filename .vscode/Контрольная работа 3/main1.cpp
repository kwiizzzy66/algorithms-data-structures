#include <iostream>
using namespace std;

int count(int n) {
    if (n < 10) {
        return 1;
    }
    return 1 + count(n / 10);
}

int main() {  
    int number;
    cout << "vvedite chislo: ";
    cin >> number;
    
    cout << "kol-vo cifr: " << count(number) << endl;
    
    return 0;
}