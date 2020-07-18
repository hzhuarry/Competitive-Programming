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
int cmp[100001];
vi adj[100001];
bool vis[100001];
bool poss=1;
 
void dfs(int i,int c){
    vis[i]=1;
    cmp[i]=c;
    for(auto u:adj[i]){
        if(cmp[u]==c){
            poss=0;
            return;
        }
        if(!vis[u]){
            dfs(u,3-c);
        }
    }
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
    int c=1;
    for(int i=1;i<=n;++i){
        if(!vis[i]){
            dfs(i,c);
        }
    }
    if(!poss){
        cout<<"IMPOSSIBLE"<<endl;
        return 0;
    }
    for(int i=1;i<=n;++i){
        cout<<cmp[i]<<" ";
    }
    cout<<endl;
    return 0;
}
