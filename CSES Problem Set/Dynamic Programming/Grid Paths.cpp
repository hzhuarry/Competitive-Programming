#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;
int n, dp[1005][1005];
char grid[1001][1001];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(int i=1; i<=n; ++i) 
        for(int j=1; j<=n; ++j)
            cin >> grid[i][j];

    dp[1][1] = grid[1][1] == '.';
    for(int i=1; i<=n; ++i) {
        for(int j=1; j<=n; ++j) {
            if(grid[i+1][j]!='*')
                dp[i+1][j] = (dp[i+1][j] + dp[i][j]) % mod;
            if(grid[i][j+1]!='*')
                dp[i][j+1] = (dp[i][j+1] + dp[i][j]) % mod;
        }
    }
    cout << dp[n][n];
    return 0;
}


