#include <bits/stdc++.h>
using namespace std;

int n, k, p, a[50][30];
int dp[51][1501];

void solve() {
    memset(dp, 0, sizeof(dp));
    cin >> n >> k >> p;
    for(int i=0; i<n; ++i) {
        for(int j=0; j<k; ++j) {
            cin >> a[i][j];
        }
    }

    /* push dp */
    for(int i=0; i<n; ++i) {
        for(int j=0; j<=p; ++j) {
            int s = 0;
            for(int l=0; l<=k; ++l) {
                if(j+l > p)
                    break;
                dp[i+1][j+l] = max(dp[i+1][j+l], dp[i][j] + s);
                if(l != k)
                    s += a[i][l];
            }
        }
    }
    cout << dp[n][p] << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;
    for(int tt=1; tt<=T; ++tt) {
        cout << "Case #" << tt << ": ";
        solve();
    }
    return 0;
}


