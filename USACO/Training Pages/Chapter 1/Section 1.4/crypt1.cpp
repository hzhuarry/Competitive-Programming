/*
ID: hzhu7271
LANG: C++
TASK: crypt1
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
    cout << x << endl;
}

void setIO(string filename) {
    freopen((filename+".in").c_str(), "r", stdin);
    freopen((filename+".out").c_str(), "w", stdout);
}

const int MOD = 1000000007, MOD2 = 998244353;
const ll INF=1e18;
const int dx[4]= {-1,1,0,0}, dy[4]= {0,0,-1,1};

///complete search///

int N,ans;
set<int> se;
vector<int> v;

bool ok(int i,int j,int k,int x,int y){
    int one_prod1=k*y;
    int bring1 = one_prod1/10;
    one_prod1%=10;

    int ten_prod1 = j*y + bring1;
    int bring2 = ten_prod1/10;
    ten_prod1%=10;

    int hund_prod1 = i*y + bring2;
    if(hund_prod1 > 9)return 0;
    if(se.find(one_prod1)==se.end() || se.find(ten_prod1)==se.end() || se.find(hund_prod1)==se.end())return 0;
    int ten_prod2 = k*x;
    int carry1 = ten_prod2/10;
    ten_prod2%=10;

    int hund_prod2 = j*x+carry1;
    int carry2=hund_prod2/10;
    hund_prod2%=10;

    int thous_prod=i*x+carry2;
    if(thous_prod > 9)return 0;
    if(se.find(ten_prod2)==se.end() || se.find(hund_prod2)==se.end() || se.find(thous_prod)==se.end())return 0;

    int ten_sum=ten_prod1 + ten_prod2;
    if(ten_sum > 9){
        hund_prod1+=1;
        ten_sum-=10;
    }
    int hund_sum=hund_prod1 + hund_prod2;
    if(hund_sum > 9){
        thous_prod+=1;
        hund_sum-=10;
    }
    if(se.find(ten_sum)==se.end() || se.find(hund_sum)==se.end() || se.find(thous_prod)==se.end())return 0;
    return 1;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    setIO("crypt1");
    read(N);
    for(int i=0;i<N;++i){
        int x; read(x);
        v.pb(x);
        se.ins(x);
    }
    Sort(v);
    for(int i=0;i<N;++i){
        for(int j=0;j<N;++j){
            for(int k=0;k<N;++k){
                for(int x=0;x<N;++x){
                    for(int y=0;y<N;++y){
                        if(ok(v[i],v[j],v[k],v[x],v[y]))
                            ans++;
                    }
                }
            }
        }
    }
    write(ans);
    return 0;
}
