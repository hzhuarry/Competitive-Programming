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
const ll INF=1e16;
const int dx[4]= {-1,1,0,0}, dy[4]= {0,0,-1,1}; //flood
 
//the num in each cell will be a possible pos at num seconds
int n,m,px,py,monsters[1000][1000],person[1000][1000];
queue<pii> q;
str dir[4]={"D","U","R","L"};
vs ans;
 
bool ok(int i,int j){
    return i>=0&&j>=0&&i<n&&j<m;
}
 
void dfs(int i,int j){
    if(i==px&&j==py) return;
 
    for(int k=0;k<4;++k){
        int ni=i+dx[k],nj=j+dy[k];
        if(ok(ni,nj)&&person[ni][nj]==person[i][j]-1){
            ans.pb(dir[k]);
            dfs(ni,nj);
            break;
        }
    }
}
 
bool okP(int i,int j,int t){
    return i>=0&&j>=0&&i<n&&j<m&&person[i][j]==0&&(monsters[i][j]>t||monsters[i][j]==0);
 
}
 
void bfsPerson(){
    queue<pii> q;
    q.push({px,py});
    while(!q.empty()){
        int x=q.front().f,y=q.front().s,t=person[x][y];
        q.pop();
 
        //we have reached an edge and are finished
        if(x==0||y==0||x==n-1||y==m-1){
            cout<<"YES"<<endl;
            cout<<t-1<<endl;
            //backtrack the path
            dfs(x,y);
            for(int s=ans.size()-1;s>=0;--s){
               cout<<ans[s];
            }
            exit(0);
        }
        for(int k=0;k<4;++k){
            int nx=x+dx[k],ny=y+dy[k],nt=t+1;
            if(okP(nx,ny,nt)){
                q.push({nx,ny});
                person[nx][ny]=nt;
            }
        }
    }
}
 
bool okM(int i,int j){
    //not out of bounds or a wall
    return i>=0&&j>=0&&i<n&&j<m&&monsters[i][j]==0;
}
 
void bfsMonster(){
    while(!q.empty()){
        int x=q.front().f,y=q.front().s,t=monsters[x][y];
        q.pop();
        for(int k=0;k<4;++k){
            int nx=x+dx[k],ny=y+dy[k],nt=t+1;
            if(okM(nx,ny)){
                q.push({nx,ny});
                monsters[nx][ny]=nt;
            }
        }
    }
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
 
    cin>>n>>m;
    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j){
            char ch;
            cin>>ch;
            if(ch=='#'){
                monsters[i][j]=-1;
                person[i][j]=-1;
            }
            else if(ch=='M'){
                monsters[i][j]=1;
                q.push({i,j});
            }
            else if(ch=='A'){
                person[i][j]=1;
                px=i;
                py=j;
            }
        }
    }
    //bfs all monsters
    bfsMonster();
    //bfs person
    bfsPerson();
    cout<<"NO"<<endl;
    return 0;
}
