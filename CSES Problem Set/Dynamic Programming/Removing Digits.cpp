#include <bits/stdc++.h>
using namespace std;

int n, dp[1000001];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    memset(dp, 0x3f, sizeof(dp));
    dp[n] = 0;
    for(int i=n; i>0; --i) {
        string ss = to_string(i);
        for(char c : ss) {
            dp[i-(c-'0')] = min(dp[i-(c-'0')], dp[i]+1);
        }
    }
    cout << dp[0];
    return 0;
}


