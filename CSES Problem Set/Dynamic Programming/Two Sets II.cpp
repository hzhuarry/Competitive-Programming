#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;
int n, sum;
int dp[501][125251];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    sum = n*(n+1)/2;

    if(sum % 2 == 1) {
        cout << 0; 
        return 0;
    }

    dp[0][0] = 1;
    for(int i=1; i<n; ++i) {
        for(int x=0; x<=sum/2; ++x) {
            dp[i][x] = dp[i-1][x];
            if(x - i >= 0) {
                dp[i][x] = (dp[i][x] + dp[i-1][x-i]) % mod;
            }
        }
    }
    cout << dp[n-1][sum/2];
    return 0;
}
