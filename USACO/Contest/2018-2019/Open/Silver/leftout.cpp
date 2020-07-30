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

/* INPUT */
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

/* OUTPUT */
template<class T> void write(T x) {
    cout << x << endl;
}

/* FILE IO */
void setIO(string filename = "") {
    ios_base::sync_with_stdio(0); cin.tie(0);
    if (sz(filename)) { /* USACO */
        freopen((filename+".in").c_str(), "r", stdin);
        freopen((filename+".out").c_str(), "w", stdout);
    }
}

const int MOD = 1e9+7, MOD2 = 998244353;
const int MX = 2e5+5;
const ll INF=1e18;
const ld PI = acos((ld)-1);
const int dx[4] = {-1,1,0,0}, dy[4] = {0,0,-1,1};


/* Pretty much the official solution */

int N;
bool grid[1000][1000];

int count(int i1,int j1,int i2,int j2,bool b){
    int cnt=0;
    for(int i=i1;i<=i2;++i){
        for(int j=j1;j<=j2;++j){
            if(grid[i][j]==b)
                cnt++;
        }
    }
    return cnt;
}

int main() {
    setIO("leftout");
    read(N);
    FOR(i,N){
        str s; read(s);
        FOR(j,N){
            grid[i][j]=s[j]=='L'?1:0;
        }
    }
    //flip to have the top row and the leftmost col to be 0
    FOR(i,1,N){
        grid[i][0]^=grid[0][0];
        FOR(j,1,N){
            grid[i][j]^=grid[i][0]^grid[0][j];
        }
    } 

    if(count(1,1,N-1,N-1,0)==0){
        cout << "1 1" << endl;
        return 0;
    }
    else if(count(1,1,N-1,N-1,1)==N-1){
        for(int i=1;i<N;++i){
            if(count(i,1,i,N-1,1)==N-1){
                cout << i+1 << " " << 1 << endl;
                return 0;
            }
        }
        for(int j=1;j<N;++j){
            if(count(1,j,N-1,j,1)==N-1){
                cout << 1 << " " << j+1 << endl;
                return 0;
            }
        }
        cout << -1 << endl;
        return 0;
    }
    else if(count(1,1,N-1,N-1,1)!=1){
        cout << -1 << endl;
        return 0;
    }
    FOR(i,1,N){
        FOR(j,1,N){
            if(grid[i][j])
                cout << i +1 << " " << j+1 << endl;
        }
    }
    return 0;
}
