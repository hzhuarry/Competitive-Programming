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

int N,grid[4001][4001];
bool vis[4001][4001];
str s;
void ff(int i,int j){
    if(i<1||j<1||i>400||j>400||vis[i][j]||grid[i][j]==1)return;
    vis[i][j]=1;
    for(int k=0;k<4;++k){
        ff(i+dx[k],j+dy[k]);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    ifstream cin ("gates.in");
    ofstream cout ("gates.out");
    //tbh idk why it works but it works
    cin>>N>>s;
    int x=200,y=200;
    for(int i=0;i<N;++i){
        char c=s[i];
        int changeX=0,changeY=0;
        if(c=='N'){
            changeY=1;
        }
        else if(c=='S'){
            changeY=-1;
        }
        else if(c=='E'){
            changeX=1;
        }
        else{
            changeX=-1;
        }
        for(int i=0;i<2;++i){
            x+=changeX;
            y+=changeY;
            //1 means gate there
            grid[x][y]=1;
        }
    }
    int cmp=0;
    for(int i=1;i<=400;++i){
        for(int j=1;j<=400;++j){
            //we dont want to ff the gate
            if(!vis[i][j]&&grid[i][j]==0){
                ff(i,j);
                cmp++;
            }
        }
    }
    cout<<cmp-1<<endl;
    return 0;
}
