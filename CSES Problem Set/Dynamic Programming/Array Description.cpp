#include <bits/stdc++.h>
using namespace std;
 
const int mod = 1e9 + 7;
const int dx[3] = {-1, 0, 1};
int n, m, x[100000];
/* dp[i][v] = number of ways to fill the array up to index i, if x[i] = v. */
int dp[100000][101];
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
 
    cin >> n >> m;
    for(int i=0; i<n; ++i)
        cin >> x[i];
 
    if(x[0] == 0) {
        for(int i=1; i<=m; ++i) {
            dp[0][i] = 1;
        }
    }
    else {
        dp[0][x[0]] = 1;
    }
 
    for(int i=1; i<n; ++i) {
        if(x[i] == 0) {
            for(int j=1; j<=m; ++j) {
                for(int k=0; k<3; ++k) {
                    if(j+dx[k]>=1 and j+dx[k]<=m) {
                        dp[i][j] = (dp[i][j] + dp[i-1][j+dx[k]]) % mod;
                    }
                }
            }
        }
        else {
           for(int k=0; k<3; ++k) {
                dp[i][x[i]] = (dp[i][x[i]] + dp[i-1][x[i]+dx[k]]) % mod;
            }
        }
    }
 
    int res = 0;
    for(int i=1; i<=m; ++i)
        res = (res + dp[n-1][i]) % mod;
    cout << res;
    return 0;
} 
