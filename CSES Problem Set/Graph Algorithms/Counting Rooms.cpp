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
char grid[1000][1000];
bool vis[1000][1000];
 
void ff(int i,int j){
    if(vis[i][j]||i<0||j<0||i>=n||j>=m||grid[i][j]!='.') return;
    vis[i][j]=1;
    for(int k=0;k<4;++k){
        ff(i+dx[k],j+dy[k]);
    }
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin>>n>>m;
    for(int i=0;i<n;++i)
    {
        str s;
        cin>>s;
        for(int j=0;j<m;++j){
            grid[i][j]=s[j];
        }
    }
    int ans=0;
    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j){
            if(!vis[i][j]&&grid[i][j]=='.'){
                ans++;
                ff(i,j);
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}
