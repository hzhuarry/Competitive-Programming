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

/* TO_STRING */
string to_string(char c) {
    return string(1, c);
}
string to_string(const char* s) {
    return string(s);
}
string to_string(string s) {
    return s;
}
string to_string(bool b) {
    #ifdef local
        return b?"true":"false";
    #else
        return to_string((int)b);
    #endif
}
string to_string(vector<bool> v) {
    string res;
    FOR(sz(v))
        res+=char('0'+v[i]);
    return res;
}
template<size_t S> string to_string(bitset<S> b) {
    string res;
    FOR(S)
        res+=char('0'+b[i]);
    return res;
}
template<class A, class B> string to_string(pair<A,B> p) {
    #ifdef local
        return "("+to_string(p.f)+", "+to_string(p.s)+")";
    #else
        return to_string(p.f)+" "+to_string(p.s);
    #endif
}
template<class T> string to_string(T v) {
    #ifdef local
        bool fst = 1;
        string res = "{";
        trav(x,v){
            if(!fst)
                res+=", ";
            fst=0;
            res+=to_string(x);
        }
        res+="} ";
        return res;
    #else
        bool fst = 1;
        string res = "";
        trav(x,v) {
            if (!fst)
                res += " ";
            fst = 0;
            res += to_string(x);
        }
        return res;
    #endif
}

/* OUTPUT */
template<class A> void write(A x) {
    cout << to_string(x);
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
    if(sizeof...(t))
        write(' ');
    print(t...);
}
/* DEBUG */
void DBG() {
    cerr << "]" << endl;
}
template<class H, class... T> void DBG(H h, T... t) {
    cerr << to_string(h);
    if(sizeof...(t))
        cerr << ", ";
    DBG(t...);
}
#ifdef local
#define dbg(...) cerr << "LINE(" << __LINE__ << ") -> [" << #__VA_ARGS__ << "]: [", DBG(__VA_ARGS__)
#else
#define dbg(...) 0
#endif

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

void solve(){
    int n; read(n);
    map<int,int> m;
    FOR(n){
        int a; read(a);
        m[a]++;
    }
    vi v;
    FIT(it,m){
        v.pb(it->s);    
    }
    sort(all(v),greater<int>());
    vector<bool> seen(2e5+1,0);
    int ans=0, curr_low=v[0];
    trav(i,v){
        if(!seen[i]){
            ans+=i;
            seen[i]=1;
        }
        else{
            dbg(curr_low);
            if(i<=curr_low){
                curr_low=i-1;
            }
            if(curr_low==0){
                break;
            }
            else if(!seen[curr_low]){
                ans+=curr_low;
                seen[curr_low]=1;
                --curr_low;
            }
        }
    }
    print(ans);
}

int main() {
    setIO();
    int q; read(q);
    while(q--){
        solve();
    }
    return 0;
}

