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
const int dx[4]= {-1,1,0,0}, dy[4]= {0,0,-1,1};
 
char grid[8][8];
int ans;
 
bool ok(int row,int col)
{
    if(grid[row][col]=='*')return 0;
    for(int i=0;i<8;++i){
        if(grid[row][i]=='Q')return 0;
    }
    for(int i=row,j=col;j>=0,i>=0;--j,--i){
        if(grid[i][j]=='Q') return 0;
    }
    for(int i=row,j=col;i<8,j>=0;++i,--j){
        if(grid[i][j]=='Q')return 0;
    }
    return 1;
}
 
void solve(int col){
    if(col==8){
        ans++;
        return;
    }
    for(int i=0;i<8;++i){
        if(ok(i,col)){
            grid[i][col]='Q';
            solve(col+1);
            grid[i][col]='.';
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    for(int i=0;i<8;++i){
        str s;
        cin>>s;
        for(int j=0;j<8;++j){
            grid[i][j]=s[j];
        }
    }
    solve(0);
    cout<<ans<<endl;
    return 0;
}
