#include <bits/stdc++.h>
using namespace std;

int n, x, c[100], dp[1000001];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> x;
    for(int i=0; i<n; ++i)
        cin >> c[i];

    memset(dp, 0x3f, sizeof(dp));
    dp[0] = 0;
    for(int i=0; i<x; ++i) {
        for(int j=0; j<n; ++j) {
            if(i+c[j]<=x)
                dp[i+c[j]] = min(dp[i+c[j]], dp[i]+1);
        }
    }

    if(dp[x]>=1e9)
        dp[x] = -1;
    cout << dp[x];
    return 0;
}


