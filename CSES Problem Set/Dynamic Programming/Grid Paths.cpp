#include <bits/stdc++.h>

using namespace std;
#define pb push_back
using ll = long long;

/* FILE IO */
void setIO(string filename = "") {
    ios_base::sync_with_stdio(0); cin.tie(0);
    if ((int)filename.size()) { /* USACO */
        freopen((filename+".in").c_str(), "r", stdin);
        freopen((filename+".out").c_str(), "w", stdout);
    }
}

const ll MOD=1e9+7;
int n;
int grid[1001][1001];

int main(){
    setIO();
    cin >> n;
    for(int i=1;i<=n;++i){
        string s; cin >> s;
        for(int j=0;j<n;++j){
            grid[i][j+1]=s[j]=='.'?1:0;
        }
    }
    for(int i=1;i<=n;++i){
        for(int j=1;j<=n;++j){
            if((i==1&&j==1) || grid[i][j]==0) continue;
            grid[i][j]=grid[i-1][j]+grid[i][j-1];
            grid[i][j]%=MOD;
        }
    }
    cout << grid[n][n] << endl;
    return 0;
}
