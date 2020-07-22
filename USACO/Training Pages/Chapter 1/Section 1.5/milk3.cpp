/*
ID: hzhu7271
LANG: C++
TASK: milk3
*/

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

#define endl "\n"
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define sz(x) (int)x.size()
#define all(x) begin(x), end(x)
#define alla(x,n) x,x+n
#define rall(x) (x).rbegin(), (x).rend()
#define Sort(x) sort(all(x))
#define Sorta(x,n) sort(alla(x,n))
#define rsz resize
#define ins insert
#define lb lower_bound
#define ub upper_bound
#define umap unordered_map
#define uset unordered_set
#define pqueue priority_queue
#define ar array

#define for_base(i, a, b, x) for (int i=((a)<(b))?(a):(a)-1; ((a)<(b))?i<(b):i>=(b); ((a)<(b))?i+=(x):i-=(x))
#define FOR1(a) for_base(i, 0, a, 1)
#define FOR2(i, a) for_base(i, 0, a, 1)
#define FOR3(i, a, b) for_base(i, a, b, 1)
#define FOR4(i, a, b, x) for_base(i, a, b, x)
#define FIFTH(a, b, c, d, e, ...) e
#define FOR(...) FIFTH(__VA_ARGS__, FOR4, FOR3, FOR2, FOR1)(__VA_ARGS__)
#define trav(a,x) for (auto& a: x)
#define FIT(i, x) for (auto i=(x).begin(); i!=(x).end(); ++i)
#define RIT(i, x) for (auto i=(x).rbegin(); i!=(x).rend(); ++i)

typedef long long ll;
typedef long double ld;
typedef double db;
typedef string str;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<db,db> pdd;
typedef pair<ld,ld> pld;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<db> vd;
typedef vector<str> vs;
typedef vector<ld> vld;
typedef vector<pii> vpii;
typedef vector<pll> vpll;
typedef vector<pld> vpld;
typedef vector<pdd> vpdd;
template<class T> using min_heap=pqueue<T, vector<T>, greater<T>>;
template<class T> using oset=tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

template<class T> bool umin(T& a, const T& b) {
    return b < a ? a = b, 1 : 0; }
template<class T> bool umax(T& a, const T& b) {
    return a < b ? a = b, 1 : 0; }

//Read In
template<class T> void read(T& x) {
    cin >> x;
}
template<class H, class T> void read(pair<H, T>& p) {
    cin >> p.f >> p.s;
}
template<class A, size_t S> void read(array<A, S>& x) {
    trav(a, x)
        read(a);
}
template<class T> void read(vector<T>& v) {
    trav(i, v)
        read(i);
}
template<class T> void read(T a[], int n) {
    FOR(n)
        read(a[i]);
}
template<class H, class... T> void read(H& h, T&... t) {
    read(h);
    read(t...);
}
//Write Out
template<class T> void write(T x) {
    cout << x;
}


void setIO(string filename) {
    freopen((filename+".in").c_str(), "r", stdin);
    freopen((filename+".out").c_str(), "w", stdout);
}

const int MOD = 1000000007, MOD2 = 998244353;
const ll INF=1e18;
const int dx[4]= {-1,1,0,0}, dy[4]= {0,0,-1,1};

int a,b,c;
set<int> ans;
bool vis[20][20][20];

void solve(int x=0,int y=0,int z=c){
    if(x==0){
        ans.ins(z);
    }
    
    //to prevent inf recursion
    if(vis[x][y][z])return;
    vis[x][y][z]=1;
    
    //z to x
    if(z&&x<a){
        if(x+z>=a){
            solve(a,y,x+z-a);
        }
        else{
            solve(x+z,y,0);
        }
    }
    //z to y
    if(z&&y<b){
        if(z+y>=b){
            solve(x,b,z+y-b);
        }
        else{
            solve(x,z+y,0);
        }
    }
    //x to y
    if(x&&y<b){
        if(x+y>=b){
            solve(x+y-b,b,z);
        }
        else{
            solve(0,x+y,z);
        }
    }
    //x to z
    if(x&&z<c){
        if(x+z>=c){
            solve(x+z-c,y,c);
        }
        else{
            solve(0,y,x+z);
        }
    }
    //y to x
    if(y&&x<a){
        if(x+y>=a){
            solve(a,x+y-a,z);
        }
        else{
            solve(x+y,0,z);
        }
    }
    //y to z
    if(y&&z<c){
        if(y+z>=c){
            solve(x,y+z-c,c);
        }
        else{
            solve(x,0,y+z);
        }
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    setIO("milk3");
    read(a,b,c);
    solve();
    FIT(it,ans){
        if(next(it)==ans.end())
            cout<<*it<<endl;
        else 
            cout<<*it<<" ";
    }
    return 0;
}
