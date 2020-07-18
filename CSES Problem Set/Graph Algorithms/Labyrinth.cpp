#include <bits/stdc++.h>

using namespace std;
 
#define endl "\n"
#define pf push_front
#define pb(s) push_back(s)
#define mp(a,b) make_pair(a,b)
#define f first
#define s second
#define ALL(v) v.begin(), v.end()
#define ALLA(arr, sz) arr, arr + sz
#define SORT(v) sort(ALL(v))
#define REVERSE(v) reverse(ALL(v))
#define SORTA(arr, sz) sort(ALLA(arr, sz))
#define REVERSEA(arr, sz) reverse(ALLA(arr, sz))
#define PI 3.14159265358979323846264338327950L
#define lb lower_bound
#define ub upper_bound
 
typedef long long ll;
typedef long double ld;
typedef string str;
 
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<ld,ld> pld;
 
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<char> vc;
typedef vector<str> vs;
typedef vector<ld> vd;
 
typedef vector<pii> vpii;
typedef vector<pll> vpll;
typedef vector<pld> vpd;
 
const int MOD = 1000000007;
const int dx[4]= {-1,1,0,0}, dy[4]= {0,0,-1,1}; //flood
 
int n,m,ax,ay,bx,by,dist[1000][1000];
char grid[1000][1000];
vi path;
str dir[4]={"D","U","R","L"};
 
 
void dfs(int x, int y){
    if(dist[x][y]==0)return;
    for(int k=0;k<4;++k){
        int nx=x+dx[k],ny=y+dy[k];
        if(nx>=0&&nx<n&&ny>=0&&ny<m&&dist[nx][ny]==dist[x][y]-1){
            path.pb(k);
            dfs(nx,ny);
            break;
        }
    }
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    cin>>n>>m;
    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j){
            char c;
            cin>>c;
            if(c=='A'){
                ax=i;
                ay=j;
            }
            else if(c=='B'){
                bx=i;
                by=j;
            }
            grid[i][j]=c;
            dist[i][j]=1e9;
        }
    }
    dist[ax][ay]=0;
    queue<pii> q;
    q.push(mp(ax,ay));
    while(!q.empty()){
        int x=q.front().first, y=q.front().second, d=dist[x][y];
        q.pop();
        if(x==bx&&y==by){
            dfs(x,y);
            cout<<"YES"<<endl;
            cout<<d<<endl;
            for(int p=path.size()-1;p>=0;--p){
                cout<<dir[path[p]];
            }
            cout<<endl;
            return 0;
        }
        if(x+1<n&&dist[x+1][y]==1e9&&grid[x+1][y]!='#'){
            q.push(mp(x+1,y));
            dist[x+1][y]=d+1;
        }
        if(x-1>=0&&dist[x-1][y]==1e9&&grid[x-1][y]!='#'){
            q.push(mp(x-1,y));
            dist[x-1][y]=d+1;
        }
        if(y+1<m&&dist[x][y+1]==1e9&&grid[x][y+1]!='#'){
            q.push(mp(x,y+1));
            dist[x][y+1]=d+1;
        }
        if(y-1>=0&&dist[x][y-1]==1e9&&grid[x][y-1]!='#'){
            q.push(mp(x,y-1));
            dist[x][y-1]=d+1;
        }
    }
    cout<<"NO"<<endl;
    return 0;
}
