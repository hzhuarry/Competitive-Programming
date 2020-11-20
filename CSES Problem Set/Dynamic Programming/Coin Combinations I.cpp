#include <bits/stdc++.h>
using namespace std;

#define ll long long

const ll mod = 1e9 + 7;
ll n, x, c[100], dp[1000001];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> x;
    for(int i=0; i<n; ++i)
        cin >> c[i];

    dp[0] = 1;
    for(ll i=0; i<x; ++i) {
        for(ll j=0; j<n; ++j) {
            if(i+c[j]<=x) {
                dp[i+c[j]] = (dp[i+c[j]] + dp[i]) % mod;
            }
        }
    }
    cout << dp[x];
    return 0;
}


