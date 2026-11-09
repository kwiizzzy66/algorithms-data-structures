#include <iostream>
using namespace std;

int next(int n) {
    return (n / 2 + 1) * 2;
}

int main() {
    int n;
    cin >> n;
    cout << next(n);

    return 0;
}
