#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define ar array

typedef long long ll;
typedef string str;

void setIO(string filename = "") {
    ios_base::sync_with_stdio(0); cin.tie(0);
    if ((int)filename.size()) {
        freopen((filename+".in").c_str(), "r", stdin);
        freopen((filename+".out").c_str(), "w", stdout);
    }
}

int R,C,K;
const int MOD=1e9+7;
int grid[100][100];
ll dp[100][100];

int solve(int x,int y){
    ll sum=0;
    for(int i=x-1;i>=0;--i){
        for(int j=y-1;j>=0;--j){
            if(grid[i][j]!=grid[x][y]){
                sum+=dp[i][j];
            }
        }
    }
    return sum%MOD;
}

int main() {
    setIO("hopscotch");
    cin >> R >> C >> K;
    for(int i=0;i<R;++i){
        for(int j=0;j<C;++j){
            cin >> grid[i][j];
        }
    }
    dp[0][0]=1;
    for(int i=1;i<R;++i){
        for(int j=1;j<C;++j){
            dp[i][j]=solve(i,j);
        }
    }
    cout << dp[R-1][C-1] << endl;
    return 0;
}

