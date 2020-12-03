#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int n;
ll x[5005];
pair<ll, ll> dp[5005][5005];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
 
    cin >> n;
    for(int i=0; i<n; ++i)
        cin >> x[i];

    for(int i=n-1; ~i; --i) {
        for(int j=i; j<n; ++j) {
            if(i==j) {
                dp[i][j]={x[i], 0};
            }
            else {
                if(dp[i+1][j].second+x[i]>dp[i][j-1].second+x[j])
                    dp[i][j]={dp[i+1][j].second+x[i], dp[i+1][j].first};
                else
                    dp[i][j]={dp[i][j-1].second+x[j], dp[i][j-1].first};
            }
        }
    }

    cout << dp[0][n-1].first;
    return 0;
} 
