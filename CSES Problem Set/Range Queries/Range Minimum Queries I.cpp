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
#define fitfor(i, x) for (auto i=(x).begin(); i!=(x).end(); ++i)
#define ritfor(i, x) for (auto i=(x).rbegin(); i!=(x).rend(); ++i)

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
template<class T> void re(T& x) {
    cin >> x;
}
template<class H, class T> void re(pair<H, T>& p) {
    cin >> p.f >> p.s;
}
template<class A, size_t S> void re(array<A, S>& x) {
    trav(a, x)
        re(a);
}
template<class T> void re(vector<T>& v) {
    trav(i, v)
        re(i);
}
template<class T> void re(T a[], int n) {
    FOR(n)
        re(a[i]);
}
template<class H, class... T> void re(H& h, T&... t) {
    re(h);
    re(t...);
}
//Write Out
template<class T> void write(T x) {
    cout << x;
}

const int MOD = 1000000007, MOD2 = 998244353;
const ll INF = 1e18;
const int dx[4] = {-1,1,0,0}, dy[4]= {0,0,-1,1};

ll n,q;
ll a[200001];
ll seg[4 * 200001];

void build(int ind=0, int l=0, int h=n-1){
    if(l==h){
        seg[ind] = a[l];
        return;
    }
    else{
        int mid = (l+h)/2;
        build(2*ind+1,l,mid);
        build(2*ind+2,mid+1,h);
        seg[ind] = min(seg[2*ind+1], seg[2*ind+2]);
    }
}

ll query(int l, int r, int ind=0, int leftB=0, int rightB=n-1){
    if(l > rightB || r < leftB) return INF;
    if(l <= leftB && r >= rightB) return seg[ind];
    int mid = (rightB+leftB)/2;
    return min(query(l,r,2*ind+1,leftB,mid), query(l,r,2*ind+2,mid+1,rightB));
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    re(n,q);
    FOR(n){
        re(a[i]);
    }
    build();
    FOR(q){
        int a,b;
        re(a,b);
        //0-based indexing
        cout << query(a-1,b-1) << endl;
    }
    return 0;
}
