#include <iostream>
using namespace std;

void sandw(int n, int from, int to, int aux) {
    if (n == 0) return;

    sandw(n - 1, from, aux, to);            
    cout << "Ingredient " << n
         << " move from " << from
         << " to " << to << "\n";       
    sandw(n - 1, aux, to, from);        
}

int main() {
    int n;
    cin >> n;
    sandw(n, 1, 3, 2);
    return 0;
}