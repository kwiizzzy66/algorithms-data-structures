#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

int main() {
    int N, K, L;
    cin >> N >> K >> L;

    vector<long long> a(N);
    for (auto &x : a) cin >> x;

    // Сортируем по убыванию — берём самые дорогие первыми
    sort(a.rbegin(), a.rend());

    map<long long, int> taken;  // сколько раз уже взяли каждую стоимость
    long long sum = 0;
    int count = 0;

    for (int i = 0; i < N && count < K; i++) {
        if (taken[a[i]] < L) {
            taken[a[i]]++;
            sum += a[i];
            count++;
        }
    }

    cout << sum << "\n";
    return 0;
}