#include <bits/stdc++.h>
using namespace std;
 
int a, b, dp[501][501];
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
 
    cin >> a >> b;
    memset(dp, 0x3f, sizeof(dp));
    for(int i=1; i<=a; ++i) {
        for(int j=1; j<=b; ++j) {
            if(i==j) {
                /* if its already a square we dont need to cut */
                dp[i][j] = 0;
            }
            else {
                for(int k=1; k<i; ++k) {
                    dp[i][j] = min(dp[i][j], dp[k][j] + dp[i-k][j] + 1);
                }
                for(int k=1; k<j; ++k) {
                    dp[i][j] = min(dp[i][j], dp[i][k] + dp[i][j-k] + 1);
                }
            }
        }
    }
    cout << dp[a][b];
    return 0;
} 
