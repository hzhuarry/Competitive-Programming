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

int n,m;
int grid1[50][50];
int grid2[50][50];
int cnt;
vector<pair<int,int> > ans;

int main(){
    setIO();
    cin >> n >> m;
    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j){
            cin >> grid1[i][j];
        }
    }
    for(int i=0;i<n-1;++i){
        for(int j=0;j<m-1;++j){
            if(grid1[i][j]==1){
                if(grid1[i][j+1]==1 && grid1[i+1][j]==1 && grid1[i+1][j+1]==1){
                    grid2[i][j]=grid2[i][j+1]=grid2[i+1][j]=grid2[i+1][j+1]=1;
                    ++cnt;
                    ans.pb({i+1,j+1});
                } 
            }
        }
    }
    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j){
            if(grid1[i][j]!=grid2[i][j]){
                cout << -1 << endl;
                return 0;
            }
        }
    }
    cout << cnt << endl;
    for(auto u:ans)
        cout << u.first << " " << u.second << endl;
    return 0;
}
