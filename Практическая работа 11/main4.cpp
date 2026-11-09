#include <iostream>
#include <vector>
#include <string>
using namespace std;

int N, M;
vector<string> g;
vector<vector<int>> dp;   // -1 = не посчитано

int go(int r, int c) {
    if (r < 0 || r >= N || c < 0 || c >= M) return -1000000;
    if (g[r][c] == '1') return -1000000;
    if (g[r][c] == 'E') return 0;
    if (dp[r][c] != -1) return dp[r][c];

    dp[r][c] = -1000000;  // временно, чтобы не зациклиться
    int best = max(max(go(r-1,c), go(r+1,c)), max(go(r,c-1), go(r,c+1)));
    if (best > -1000000)
        best += (g[r][c] == 'P' ? 1 : 0);
    return dp[r][c] = best;
}

int main() {
    cin >> N >> M;
    g.resize(N);
    for (auto &s : g) cin >> s;

    int sr = 0, sc = 0;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            if (g[i][j] == 'S') { sr = i; sc = j; }

    dp.assign(N, vector<int>(M, -1));
    int ans = go(sr, sc);
    cout << (ans < 0 ? 0 : ans) << "\n";
}