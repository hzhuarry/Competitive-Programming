#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll N, W;
array<ll, 2> a[100];
/* the min weight of the first i items with a value of j */
ll dp[105][100005];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> W;
    for(ll i=0; i<N; ++i)
        cin >> a[i][0] >> a[i][1];

    memset(dp, 0x3f, sizeof(dp));
    dp[0][0]=0;
    for(int i=0; i<N; ++i) {
        for(int j=0; j<100000; ++j) {
            dp[i+1][j]=min(dp[i+1][j], dp[i][j]);
            if(j+a[i][1]<=100000 and dp[i][j]+a[i][0]<=W)
                dp[i+1][j+a[i][1]]=min(dp[i+1][j+a[i][1]], dp[i][j]+a[i][0]);
        }
    }

    for(ll i=100000; i; --i)
        if(dp[N][i]<=W)
            return cout << i, 0;
    return 0;
}


