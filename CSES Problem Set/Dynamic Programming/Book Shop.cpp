#include <bits/stdc++.h>
using namespace std;

int n, x, h[1000], s[1000];
int dp[1001][100001];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> x;
    for(int i=0; i<n; ++i)
        cin >> h[i];
    for(int i=0; i<n; ++i)
        cin >> s[i];

    dp[0][0] = 0;
    for(int i=0; i<n; ++i) {
        /* @since we are pushing up, we have to modify the dp price from top down */
        for(int j=x-1; ~j; --j) {
            dp[i+1][j] = dp[i][j];
            if(j+h[i]<=x) {
                /* @ */
                dp[i+1][j+h[i]] = max(dp[i+1][j+h[i]], dp[i][j]+s[i]);
            }
        }
    }

    int res = 0;
    for(int i=1; i<=x; ++i)
        res = max(res, dp[n][i]);
    cout << res;
    return 0;
}


