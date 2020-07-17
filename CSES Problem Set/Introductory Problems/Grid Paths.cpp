#include <bits/stdc++.h>
 
using namespace std;
 
#define endl "\n"
#define sz(x) (int)x.size()
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
typedef vector<char> ch;
typedef vector<str> vs;
typedef vector<ld> vld;
typedef vector<pii> vpii;
typedef vector<pll> vpll;
typedef vector<pld> vpld;
 
const int MOD = 1000000007;
const ll INF=1e18;
const int dx[4]= {-1,1,0,0}, dy[4]= {0,0,-1,1};

 
str s;
bool vis[7][7];
int ans;
 
//can we move to this cell?
bool ok(int i,int j){
    return i>=0&&j>=0&&i<7&&j<7&&!vis[i][j];
}
 
void solve(int i,int j,int cnt=0){
    if(i==6&&j==0&&cnt==48){
        ans++;
        return;
    }
    //if it reaches the destination before visiting all other cells, the ans cannot exist
    if(i==6&&j==0)return;
 
    vis[i][j]=1;
    //going left
    if(s[cnt]=='?'||s[cnt]=='L'){
        if(j&&!vis[i][j-1]){
            if(!(!ok(i,j-2)&&ok(i-1,j-1)&&ok(i+1,j-1))) 
                solve(i,j-1,cnt+1);
        }
    }
    //going right
    if(s[cnt]=='?'||s[cnt]=='R'){
        if(j<6&&!vis[i][j+1]){
            if(!(!ok(i,j+2)&&ok(i-1,j+1)&&ok(i+1,j+1))) 
                solve(i,j+1,cnt+1);
        }
    }
    //going up
    if(s[cnt]=='?'||s[cnt]=='U'){
        if(i&&!vis[i-1][j]){
            if(!(!ok(i-2,j)&&ok(i-1,j-1)&&ok(i-1,j+1))) 
                solve(i-1,j,cnt+1);
        }
    }
    //going down
    if(s[cnt]=='?'||s[cnt]=='D'){
        if(i<6&&!vis[i+1][j]){
            if(!(!ok(i+2,j)&&ok(i+1,j-1)&&ok(i+1,j+1))) 
                solve(i+1,j,cnt+1);
        }
    }
    vis[i][j]=0;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    cin>>s;
    solve(0,0);
    cout<<ans<<endl;
    return 0;
}
