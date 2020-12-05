#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll N, a[3005];
pair<ll, ll> dp[3005][3005];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for(int i=0; i<N; ++i)
        cin >> a[i];

    for(int i=N-1; ~i; --i) {
        for(int j=i; j<N; ++j) {
            if(i==j) {
                dp[i][j]={a[i], 0};
            }
            else {
                if(dp[i+1][j].second+a[i]>dp[i][j-1].second+a[j])
                    dp[i][j]={dp[i+1][j].second+a[i], dp[i+1][j].first};
                else
                    dp[i][j]={dp[i][j-1].second+a[j], dp[i][j-1].first};
            }
        }
    }
    pair<ll, ll> ans=dp[0][N-1];
    cout << ans.first-ans.second;
    return 0;
}


