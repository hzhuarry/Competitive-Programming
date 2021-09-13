#include <bits/stdc++.h>
/* #include <ext/pb_ds/assoc_container.hpp> */
/* #include <ext/pb_ds/tree_policy.hpp> */
using namespace std;
/* using namespace __gnu_pbds; */

#define endl '\n'
#define pb push_back
#define fi first
#define se second
#define sz(x) (int)x.size()
#define all(x) begin(x), end(x)
#define rall(x) (x).rbegin(), (x).rend()
#define ins insert
#define pqueue priority_queue
#define ar array
#define vt vector

#define for_base(i, a, b, x) for (int i=((a)<(b))?(a):(a)-1; ((a)<(b))?i<(b):i>=(b); ((a)<(b))?i+=(x):i-=(x))
#define FOR1(a) for_base(i, 0, a, 1)
#define FOR2(i, a) for_base(i, 0, a, 1)
#define FOR3(i, a, b) for_base(i, a, b, 1)
#define FOR4(i, a, b, x) for_base(i, a, b, x)
#define FIFTH(a, b, c, d, e, ...) e
#define FOR(...) FFTH(__VA_ARGS__, FOR4, FOR3, FOR2, FOR1)(__VA_ARGS__)
#define trav(a, x) for (auto& a: x)
#define FIT(i, x) for (auto i=(x).begin(); i!=(x).end(); ++i)
#define RIT(i, x) for (auto i=(x).rbegin(); i!=(x).rend(); ++i)
#define finish(...) return void(print(__VA_ARGS__))

typedef long long ll;
typedef long double ld;
typedef string str;

template<class T> using min_queue = pqueue<T, vector<T>, greater<T>>;
/* template<class T> using oset = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>; */

template<class T> bool umin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool umax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

template<class T> void read(T& x) { cin >> x; }
template<class H, class T> void read(pair<H, T>& p) { cin >> p.f >> p.s; }
template<class A, size_t S> void read(array<A, S>& x) { trav(a, x) read(a); }
template<class T> void read(vector<T>& v) { trav(i, v) read(i); }
template<class H, class... T> void read(H& h, T&... t) { read(h); read(t...); }

template<class H, class T> ostream &operator<<(ostream &o, pair<H, T> &p) { o << p.fi << " " << p.se; return o; }
template<class H, class T> ostream &operator<<(ostream &o, vector<pair<H, T>> &v) { string s; trav(i, v) o << s << i, s = "\n"; return o; }
template<class T, size_t S> ostream &operator<<(ostream &o, array<T, S> &a) { string s; trav(i, a) o << s << i, s = " "; return o; }
template<class T, size_t S> ostream &operator<<(ostream &o, vector<array<T, S>> &v) { string s; trav(i, v) o << s << i, s = "\n"; return o; }
template<class T> ostream &operator<<(ostream &o, vector<T> &v) { string s; trav(i, v) o << s << i, s = " "; return o; }
template<class T> ostream &operator<<(ostream &o, vector<vector<T>> &v) { string s; trav(i, v) o << s << i, s = "\n"; return o; }
template<class T> void write(T x) { cout << x; }
template<class H, class... T> void write(const H &h, const T &...t) { write(h); write(t...); }
void print() { write('\n'); }
template<class H, class... T> void print(const H &h, const T &...t) { write(h); if (sizeof...(t)) write(' '); print(t...); }

void DBG() { cerr << "]" << endl; }
template<class H, class... T> void DBG(H h, T... t) { cerr << h; if(sizeof...(t)) cerr << ", "; DBG(t...); }
#ifdef local
#define dbg(...) cerr << "LINE(" << __LINE__ << ") -> [" << #__VA_ARGS__ << "]: [", DBG(__VA_ARGS__)
#else
#define dbg(...) 0
#endif

/* const ll mod = 1e9 + 7; */
/* const int dx[4] = {-1, 1, 0, 0}, dy[4] = {0, 0, -1, 1}; */

void solve() {
    int n, m, a, b;
    read(n, m, a, b);

    if(n+m-1>min(a, b))
        finish("Impossible");

    print("Possible");
    int grid[n][m];
    FOR(i, n)
        FOR(j, m)
            grid[i][j]=max(a, b);
    FOR(i, n)
        grid[i][0]=grid[i][m-1]=1;
    FOR(j, m)
        grid[0][j]=grid[n-1][j]=1;

    int sum=0;
    FOR(n)
        sum+=grid[i][0];
    int s1=sum, s2=sum;
    s1-=grid[n-1][0], s2-=grid[0][0];
    FOR(j, m)
        s1+=grid[0][j], s2+=grid[n-1][j];
    --s1, --s2;
    grid[n-1][0]=b-s1;
    grid[n-1][m-1]=a-s2;

    /* dbg */
    FOR(i, n) {
        FOR(j, m) {
            write(grid[i][j], ' ');
        }
        print(" ");
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T=1;
    read(T);
    for (int tc=1; tc<=T; ++tc) {
        write("Case #", tc, ": ");
        solve();
    }

    return 0;
}


