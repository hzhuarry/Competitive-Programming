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

const int MOD = 1000000007, MOD2 = 998244353;
const ll INF=1e18;
const int dx[4]= {-1,1,0,0}, dy[4]= {0,0,-1,1};

const int maxn=200000;
int n,m;
int h[maxn];
int seg[4*maxn];

void build(int v=1,int l=0,int r=n-1){
    if(l==r){
        seg[v]=h[l];
    }
    else{
        int mid=(l+r)/2;
        build(2*v,l,mid);
        build(2*v+1,mid+1,r);
        seg[v]=max(seg[2*v],seg[2*v+1]);
    }
}

void upd(int ind, int val, int v=1,int l=0,int r=n-1){
    if(l==r){
        seg[v]+=val;
    }
    else{
        int mid=(l+r)/2;
        if(ind<=mid)
            upd(ind,val,2*v,l,mid);
        else
            upd(ind,val,2*v+1,mid+1,r);
        seg[v]=max(seg[2*v],seg[2*v+1]);
    }
}

int query(int x,int y,int v=1,int l=0,int r=n-1){
    if(x>r||y<l)return 0;
    if(x<=l&&r<=y){
        return seg[v];
    }
    int mid=(l+r)/2;
    return max(query(x,y,2*v,l,mid),query(x,y,2*v+1,mid+1,r));
}

int find_lb(int x){
    int lo=0,hi=n-1;
    while(lo<hi){
        int mid=(lo+hi)/2;
        if(query(0,mid)>=x){
            hi=mid;
        }
        else lo=mid+1;
    }
    if(query(0,n-1)<x)lo=-1;
    return lo;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    read(n,m);
    for(int i=0;i<n;++i){
        read(h[i]);
    }
    build();
    for(int i=0;i<m;++i){
        int x;
        read(x);
        int ind = find_lb(x);
        cout << ind+1 << " ";
        if(ind!=-1)
            upd(ind,-x);
    }
    return 0;
}
