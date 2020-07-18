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
 
int n,m;
vi adj[100001];
int dist[100001];
vi dir;
 
//backtrack the path
void dfs(int x){
    dir.pb(x);
    if(x==1){
        return;
    }
    for(int i:adj[x]){
        if(dist[i]==dist[x]-1){
            dfs(i);
            break;
        }
    }
}
 
void bfs(){
    queue<int> q;
    q.push(1);
    while(!q.empty()){
        for(int k=q.size();k>0;--k){
            int x=q.front(),d=dist[x];
            q.pop();
            if(x==n){
                cout<<d<<endl;
                dfs(x);
                for(int i=dir.size()-1;i>=0;--i)
                    cout<<dir[i]<<" ";
                cout<<endl;
                return;
            }
            for(int i:adj[x]){
                if(dist[i]==1e9){
                    q.push(i);
                    dist[i]=d+1;
                }
            }
        }
    }
    cout<<"IMPOSSIBLE"<<endl;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    cin>>n>>m;
    for(int i=0;i<m;++i){
        int a,b;
        cin>>a>>b;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    for(int i=2;i<=n;++i){
        dist[i]=1e9;
    }
    dist[1]=1;
    bfs();
    return 0;
}
