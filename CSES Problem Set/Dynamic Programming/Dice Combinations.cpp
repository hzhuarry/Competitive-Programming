#include <bits/stdc++.h>
using namespace std;

#define ll long long

const ll mod = 1e9 + 7;
ll n, dp[1000001];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    dp[0] = 1;
    for(ll i=0; i<n; ++i) {
        for(int j=1; j<=6; ++j) {
            if(i+j<=n)
                dp[i+j] = (dp[i+j] + dp[i]) % mod;
        }
    }
    cout << dp[n];
    return 0;
}


