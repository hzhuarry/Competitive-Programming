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

const int dx[4]={-1,1,0,0},dy[4]={0,0,-1,1};
int h,w;
char grid[500][500];
bool vis[500][500];

bool within_bounds(int i,int j){
    return i>=0&&j>=0&&i<h&&j<w;
}

bool works(int i,int j){
    for(int k=0;k<4;++k){
        int ni=i+dx[k],nj=j+dy[k];
        if(!within_bounds(ni,nj) || grid[ni][nj]!='*')
            return 0;
    }
    return 1;
}

void ff(int x,int y){
    vis[x][y]=1;
    for(int i=x+1;i<h;++i){
        if(grid[i][y]!='*'){
            break;
        }
        vis[i][y]=1;
    }
    for(int i=x-1;i>=0;--i){
        if(grid[i][y]!='*'){
            break;
        }
        vis[i][y]=1;
    }
    for(int j=y-1;j>=0;--j){
        if(grid[x][j]!='*'){
            break;
        }
        vis[x][j]=1;
    }
    for(int j=y+1;j<w;++j){
        if(grid[x][j]!='*'){
            break;
        }
        vis[x][j]=1;
    }
}

int main(){
    setIO();
    cin >> h >> w;
    for(int i=0;i<h;++i){
        for(int j=0;j<w;++j){
            cin >> grid[i][j];
        }
    }
    bool ok=0;
    for(int i=0;i<h;++i){
        for(int j=0;j<w;++j){
            if(grid[i][j]=='*'){
                if(works(i,j)){
                    ff(i,j);
                    ok=1;
                }
            }
            if(ok) break;
        }
        if(ok) break;
    }
    //if we never seen a * then there is no +
    if(!ok){
        cout << "NO" << endl;
    }
    else{
        for(int i=0;i<h;++i){
            for(int j=0;j<w;++j){
                if(vis[i][j] || grid[i][j]=='.') continue;
                cout << "NO" << endl;
                return 0;
            }
        }
        cout << "YES" << endl;
    }
    return 0;
}
