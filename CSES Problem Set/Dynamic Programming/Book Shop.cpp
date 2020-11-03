#include <bits/stdc++.h>
using namespace std;

int n, x, h[1000], s[1000], dp[1001][100001];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> x;
    for(int i=0; i<n; ++i)
        cin >> h[i];
    for(int i=0; i<n; ++i)
        cin >> s[i];

    for(int i=1; i<=n; ++i) {
        for(int cost=1; cost<=x; ++cost) {
            dp[i][cost] = dp[i-1][cost];
            if(cost - h[i-1] >= 0) {
                dp[i][cost] = max(dp[i][cost], dp[i-1][cost - h[i-1]] + s[i-1]);
            }
        }
    }
    cout << dp[n][x] << endl;
    return 0;
}
