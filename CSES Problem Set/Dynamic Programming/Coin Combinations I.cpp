#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;
int n, x, c[100], dp[1000001];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> x;
    for(int i=0; i<n; ++i)
        cin >> c[i];

    dp[0] = 1;
    for(int cost=0; cost<=x; ++cost) {
        for(int i=0; i<n; ++i) {
            if(cost - c[i] >= 0) {
                dp[cost] = (dp[cost] + dp[cost - c[i]]) % mod;
            }
        }
    }
    cout << dp[x];
    return 0;
}


