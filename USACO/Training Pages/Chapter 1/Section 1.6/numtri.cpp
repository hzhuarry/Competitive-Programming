/*
ID: hzhu7271 
LANG: C++
TASK: numtri
*/

#include <bits/stdc++.h>

using namespace std;
using ll = long long;

/* FILE IO */
void setIO(string filename = "") {
    ios_base::sync_with_stdio(0); cin.tie(0);
    if ((int)filename.size()) { /* USACO */
        freopen((filename+".in").c_str(), "r", stdin);
        freopen((filename+".out").c_str(), "w", stdout);
    }
}

int R;
int tri[1000][1000];
int dp[1000][1000];

int main(){
    setIO("numtri");
    cin >> R;
    for(int i=0;i<R;++i){
        for(int j=0;j<=i;++j){
            cin >> tri[i][j];
        }
    }
    for(int i=0;i<R;++i){
        dp[R-1][i]=tri[R-1][i];
    }
    for(int i=R-2;i>=0;--i){
        for(int j=0;j<=i;++j){
            dp[i][j]=tri[i][j]+max(dp[i+1][j],dp[i+1][j+1]);
        }
    }
    cout << dp[0][0] << endl;
    return 0;
}
