#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N, M;
    cout << "Enter number of rows N and columns M: ";
    cin >> N >> M;
    
    vector<vector<int>> grid(N, vector<int>(M));
    cout << "Enter the map elements (" << N << "x" << M << "):" << endl;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            cin >> grid[i][j];
    
    // dp[i][j] — maximum score that can be collected
    // when reaching cell (i, j) from (0, 0), moving down and right
    vector<vector<long long>> dp(N, vector<long long>(M, 0));
    
    dp[0][0] = grid[0][0];
    
    // First row — can only come from the left
    for (int j = 1; j < M; j++)
        dp[0][j] = dp[0][j-1] + grid[0][j];
    
    // First column — can only come from above
    for (int i = 1; i < N; i++)
        dp[i][0] = dp[i-1][0] + grid[i][0];
    
    // Main fill
    for (int i = 1; i < N; i++)
        for (int j = 1; j < M; j++)
            dp[i][j] = max(dp[i-1][j], dp[i][j-1]) + grid[i][j];
    
    cout << "\n maxsum: " << dp[N-1][M-1] << endl;
    
    // Path reconstruction: go from finish to start,
    // at each step choose the cell we came from
    vector<pair<int,int>> path;
    int i = N - 1, j = M - 1;
    path.push_back({i, j});
    
    while (i > 0 || j > 0) {
        if (i == 0) {
            j--;
        } else if (j == 0) {
            i--;
        } else {
            // From which cell was it more profitable to come?
            if (dp[i-1][j] >= dp[i][j-1])
                i--;
            else
                j--;
        }
        path.push_back({i, j});
    }
    
    reverse(path.begin(), path.end());
    
    cout << "Optimal path (cell coordinates):" << endl;
    for (auto& p : path)
        cout << p.first << " " << p.second << endl;
    
    return 0;
}