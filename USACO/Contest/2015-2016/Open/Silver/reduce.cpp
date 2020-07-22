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
const int maxn=5e5+1;
int ans=2e9+5;
pair<pair<int,int>,int> cows1[maxn],cows2[maxn];
set<int> candCows;
vector<int> allCand;

//sort by y val
bool cmp(const pair<pair<int,int>,int> &a, const pair<pair<int,int>,int> &b){
    if(a.f.s==b.f.s) return a.f.f<b.f.f;
    return a.f.s<b.f.s;
}

int get_area(int a, int b, int c){
    int minx=maxn,miny=maxn,maxx=0,maxy=0;
    for(int i=0;i<N;++i){
        if(cows1[i].s==a||cows1[i].s==b||cows1[i].s==c){
            continue;
        }
        umin(minx,cows1[i].f.f);
        umin(miny,cows1[i].f.s);
        umax(maxx,cows1[i].f.f);
        umax(maxy,cows1[i].f.s);
    }
    return (maxx-minx)*(maxy-miny);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    setIO("reduce");
    read(N);
    for(int i=0;i<N;++i){
        read(cows1[i].f.f,cows1[i].f.s);
        cows1[i].s=i;
        cows2[i]=cows1[i];
    }
    sort(alla(cows1,N));
    sort(alla(cows2,N),cmp);
    //get the 3 right/left/top/bottom most cows
    //insert in set because a cow can fit multiple criteria
    for(int i=0;i<3;++i){
        candCows.ins(cows1[i].s);
        candCows.ins(cows1[N-i-1].s);
        candCows.ins(cows2[i].s);
        candCows.ins(cows2[N-i-1].s);
    }
    FIT(it,candCows){
        allCand.pb(*it);
    }
    int n=sz(allCand);
    //try to remove all combinations of 3 cows
    for(int i=0;i<n;++i){
        for(int j=i+1;j<n;++j){
            for(int k=j+1;k<n;++k){
                umin(ans,get_area(allCand[i],allCand[j],allCand[k]));
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}
