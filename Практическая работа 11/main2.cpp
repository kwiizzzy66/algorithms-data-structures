#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N, D;
    if (!(cin >> N >> D)) {
        cerr << "Input error\n";
        return 1;
    }

    vector<long long> a(N);
    for (auto &x : a)
        if (!(cin >> x)) { cerr << "Input error\n"; return 1; }

    sort(a.begin(), a.end());

    auto can = [&](long long X) {
        int days = 1;
        long long start = a[0];
        for (int i = 1; i < N; i++) {
            if (a[i] - start > X) {
                days++;
                start = a[i];
                if (days > D) return false;
            }
        }
        return true;
    };

    long long lo = 0, hi = a[N-1] - a[0];
    while (lo < hi) {
        long long mid = (lo + hi) / 2;
        if (can(mid)) hi = mid;
        else lo = mid + 1;
    }

    cout << lo << "\n";
    return 0;
}