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
#define vt vector

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
typedef string str;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<double,double> pdd;
typedef pair<ld,ld> pld;

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
template<class H, class T> ostream& operator<<(ostream& o, const pair<H, T> &p) {
    o << p.fi << " " << p.se;
    return o;
}
template<class A, size_t S> ostream& operator<<(ostream& o,const array<A, S> &a) {
    bool f=0;
    trav(i,a){
        if(f)
            o << " ";
        f=1;
        o << i;
    }
    return o;
}
template<class T> ostream& operator<<(ostream& o, vector<T> &v) {
    bool f=0;
    trav(i, v) {
        if (f)
            o << " ";
        f=1;
        o << i;
    }
    return o;
}
template<class T> ostream& operator<<(ostream& o, vector<vector<T>> &v) {
    bool f=0;
    trav(i, v) {
        if (f)
            o << '\n';
        f=1;
        o << i;
    }
    return o;
}
template<class H, class T> ostream& operator<<(ostream& o, vector<pair<H, T>> &v) {
    bool f=0;
    trav(i, v) {
        if (f)
            o << '\n';
        f=1;
        o << i;
    }
    return o;
}
template<class A, size_t S> ostream& operator<<(ostream& o, vector<array<A, S>> &v) {
    bool f=0;
    trav(i, v) {
        if (f)
            o << '\n';
        f=1;
        o << i;
    }
    return o;
}
template<class T> void write(T x) {
    cout << x;
}
template<class H, class... T> void write(const H& h, const T&... t) {
    write(h);
    write(t...);
}
void print() {
    write("\n");
}
template<class H, class... T> void print(const H& h, const T&... t) {
    write(h);
    if (sizeof...(t))
        write(' ');
    print(t...);
}

/* DEBUG */
void DBG() {
    cerr << "]" << endl;
}
template<class H, class... T> void DBG(H h, T... t) {
    cerr << h;
    if(sizeof...(t))
        cerr << ", ";
    DBG(t...);
}
#ifdef local
#define dbg(...) cerr << "LINE(" << __LINE__ << ") -> [" << #__VA_ARGS__ << "]: [", DBG(__VA_ARGS__)
#else
#define dbg(...) 0
#endif

const int MOD = 1e9+7, MOD2 = 998244353;
const int MX = 2e5+5;
const ll INF=1e18;
const ld PI = acos((ld)-1);
const int dx[4] = {-1,1,0,0}, dy[4] = {0,0,-1,1};

void solve(){
    str s; read(s);
    int lcnt=0,rcnt=0;
    int xd=0,yd=0;
    trav(c,s){
        if(c=='U'){
            --xd;
            ++lcnt;
        }
        if(c=='D'){
            ++xd;
            ++lcnt;
        }
        if(c=='L'){
            --yd;
            ++rcnt;
        }
        if(c=='R'){
            ++yd;
            ++rcnt;
        }
    }
    if(xd<0){
        int n=xd*-1;
        FOR(n){
            s.erase(s.find('U'),1);
        }
        lcnt-=n;
    }
    if(xd>0){
        FOR(xd){
            s.erase(s.find('D'),1);
        }
        lcnt-=xd;
    }
    if(yd<0){
        int n=yd*-1;
        FOR(n){
            s.erase(s.find('L'),1);
        }
        rcnt-=n;
    }
    if(yd>0){
        FOR(yd){
            s.erase(s.find('R'),1);
        }
        rcnt-=yd;
    }
    if(lcnt==0 and rcnt==0){
        print(0);
    }
    else if(lcnt==0 or rcnt==0){
        set<char> se;
        trav(c,s){
            se.ins(c);
        }
        str ans="";
        FIT(u,se){
            ans+=*u;
        }
        print(2);
        print(ans);
    }
    else{
        map<char,int> m;
        trav(c,s){
            m[c]++;
        }
        str ans="";
        FOR(m['U']){
            ans+='U';
        }
        FOR(m['R']){
            ans+='R';
        }
        FOR(m['D']){
            ans+='D';
        }
        FOR(m['L']){
            ans+='L';
        }
        print(sz(s));
        print(ans);
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t; read(t);
    while(t--)
        solve();
    return 0;
}
