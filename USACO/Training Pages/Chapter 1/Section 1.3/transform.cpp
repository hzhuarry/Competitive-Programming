/*
ID: hzhu7271
LANG: C++
TASK: transform
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

int N;

//easy online lookup for rotations
bool ok1(vector<vector<char> > a,vector<vector<char> > after){
    for (int i = 0; i < N; i++)
        for (int j = 0; j < i; j++)
            swap(a[i][j], a[j][i]);

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N/2; j++)
            swap(a[i][j], a[i][N - j - 1]);
    return a==after;
}

bool ok2(vector<vector<char> > a,vector<vector<char> > after){
    for (int i = 0; i < N / 2; i++)
        for (int j = 0; j < N; j++)
            swap(a[i][j], a[N - i - 1][N - j - 1]);

    if (N & 1) {
        for (int j = 0; j < N/2; j++)
            swap(a[N/2][j], a[N/2][N - j - 1]);
	}
    return a==after;
}

bool ok3(vector<vector<char> > a,vector<vector<char> > after){
    for (int i = 0; i < N; i++)
        for (int j = 0; j < i; j++)
            swap(a[i][j], a[j][i]);

    for (int i = 0; i < N/2; i++)
        for (int j = 0; j < N; j++)
            swap(a[i][j], a[N - i - 1][j]);
    return a==after;
}

bool ok4(vector<vector<char> > a,vector<vector<char> > after){
    for(int i=0;i<N;++i){
        for(int j=0;j<N/2;++j){
            swap(a[i][j],a[i][N-j-1]);
        }
    }
    return a==after;
}

bool ok5(vector<vector<char> > a,vector<vector<char> > after){
    for(int i=0;i<N;++i){
        for(int j=0;j<N/2;++j){
            swap(a[i][j],a[i][N-j-1]);
        }
    }
    if(ok1(a,after)||ok2(a,after)||ok3(a,after))return 1;
    return 0;
}

bool ok6(vector<vector<char> > a,vector<vector<char> > after){
    return a==after;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    setIO("transform");
    read(N);
    vector<vector<char> > before(N,vector<char>(N));
    vector<vector<char> > after(N,vector<char>(N));
    read(before,after);
    if(ok1(before,after)){
        cout<<1<<endl;
        return 0;
    }
    if(ok2(before,after)){
        cout<<2<<endl;
        return 0;
    }
    if(ok3(before,after)){
        cout<<3<<endl;
        return 0;
    }
    if(ok4(before,after)){
        cout<<4<<endl;
        return 0;
    }
    if(ok5(before,after)){
        cout<<5<<endl;
        return 0;
    }
    if(ok6(before,after)){
        cout<<6<<endl;
        return 0;
    }
    cout<<7<<endl;
    return 0;
}
