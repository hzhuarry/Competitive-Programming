#include <bits/stdc++.h>
using namespace std;

int N, K;
char a[100005];
int dp[100005][3][21];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ifstream cin("hps.in");
    ofstream cout("hps.out");

    /* H=>0, P=>1, S=>2 */

    cin >> N >> K;
    for(int i=0; i<N; ++i)
        cin >> a[i];

    if(a[0]=='S')
        dp[0][0][0]=1;
    if(a[0]=='H')
        dp[0][1][0]=1;
    if(a[0]=='P')
        dp[0][2][0]=1;

    for(int i=1; i<N; ++i) {
        for(int j=0; j<3; ++j) {
            for(int k=0; k<=K; ++k) {
                /* previous state */
                for(int x=0; x<3; ++x) {
                    if(k-(j!=x)<0)
                        continue;
                    if(a[i]=='H') {
                        dp[i][j][k] = max(dp[i][j][k], dp[i-1][x][k-(j!=x)] + (j==1));
                    }
                    else if(a[i]=='P') {
                        dp[i][j][k] = max(dp[i][j][k], dp[i-1][x][k-(j!=x)] + (j==2));
                    }
                    else {
                        dp[i][j][k] = max(dp[i][j][k], dp[i-1][x][k-(j!=x)] + (j==0));
                    }
                }
            }
        }
    }

    int res=0;
    for(int i=0; i<=K; ++i) {
        for(int j=0; j<3; ++j) {
            res = max(res, dp[N-1][j][i]);
        }
    }
    cout << res << "\n";
    return 0;
}
