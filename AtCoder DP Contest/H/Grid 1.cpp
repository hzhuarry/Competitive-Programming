#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int MOD = 1e9+7;
int H,W;
char grid[1001][1001];
ll dp[1001][1001];

int main(){
    cin >> H >> W;
    for(int i=1;i<=H;++i){
        for(int j=1;j<=W;++j){
            cin >> grid[i][j];
        }
    }
    dp[1][1] = 1;
    for(int i=1;i<=H;++i){
        for(int j=1;j<=W;++j){
            if(i==1 and j==1)
                continue;
            dp[i][j] = (dp[i-1][j] + dp[i][j-1])%MOD;
            if(grid[i][j] == '#')
                dp[i][j] = 0;
        }
    }
    cout << dp[H][W] << endl;
    return 0;
}
