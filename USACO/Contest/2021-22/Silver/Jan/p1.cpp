#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <chrono>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <string>
#include <utility>
#include <vector>
#include <queue>

/* #include <ext/pb_ds/assoc_container.hpp> */
/* #include <ext/pb_ds/tree_policy.hpp> */
using namespace std;
/* using namespace __gnu_pbds; */

#define endl '\n'
#define sz(x) (int)x.size()
#define all(x) begin(x), end(x)
#define rall(x) (x).rbegin(), (x).rend()
#define ar array
#define vt vector

#define for_base(i, a, b, x) for (int i=((a)<(b))?(a):(a)-1; ((a)<(b))?i<(b):i>=(b); ((a)<(b))?i+=(x):i-=(x))
#define FOR1(a) for_base(i, 0, a, 1)
#define FOR2(i, a) for_base(i, 0, a, 1)
#define FOR3(i, a, b) for_base(i, a, b, 1)
#define FOR4(i, a, b, x) for_base(i, a, b, x)
#define FIFTH(a, b, c, d, e, ...) e
#define FOR(...) FIFTH(__VA_ARGS__, FOR4, FOR3, FOR2, FOR1)(__VA_ARGS__)
#define EACH(a, x) for (auto& a: x)
#define FIT(i, x) for (auto i=(x).begin(); i!=(x).end(); ++i)
#define RIT(i, x) for (auto i=(x).rbegin(); i!=(x).rend(); ++i)
#define finish(...) return void(print(__VA_ARGS__))

typedef long long ll;

template<class T> using min_queue = priority_queue<T, vector<T>, greater<T> >;

/* find_by_order(x) => returns an iterator to the element at a given position */
/* order_of_key(x) => returns the position of a given element */
/* template<class T> using oset = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>; */

template<class T> bool umin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool umax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

template<class T> void read(T& x) { cin >> x; }
template<class H, class T> void read(pair<H, T>& p) { cin >> p.first >> p.second; }
template<class A, size_t S> void read(array<A, S>& x) { EACH(a, x) read(a); }
template<class T> void read(vector<T>& v) { EACH(i, v) read(i); }
template<class H, class... T> void read(H& h, T&... t) { read(h); read(t...); }

template<class H, class T> ostream &operator<<(ostream &o, pair<H, T> &p) { o << p.first << " " << p.second; return o; }
template<class H, class T> ostream &operator<<(ostream &o, vector<pair<H, T> > &v) { string s; EACH(i, v) o << s << i, s = "\n"; return o; }
template<class T, size_t S> ostream &operator<<(ostream &o, array<T, S> &a) { string s; EACH(i, a) o << s << i, s = " "; return o; }
template<class T, size_t S> ostream &operator<<(ostream &o, vector<array<T, S> > &v) { string s; EACH(i, v) o << s << i, s = "\n"; return o; }
template<class T> ostream &operator<<(ostream &o, vector<T> &v) { string s; EACH(i, v) o << s << i, s = " "; return o; }
template<class T> ostream &operator<<(ostream &o, vector<vector<T> > &v) { string s; EACH(i, v) o << s << i, s = "\n"; return o; }
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

/* const int dx[4] = {-1, 1, 0, 0}, dy[4] = {0, 0, -1, 1}; */

void solve() {
    ll a, b;
    read(a, b);

    vt<ll> v_a;
    while(a) {
        v_a.push_back(a);
        if(a > 1 and a & 1) {
            ++a;
        }
        else {
            a /= 2;
        }
    }
    vt<ll> v_b;
    while(b) {
        v_b.push_back(b);
        if(b & 1) {
            --b;
        }
        else {
            b /= 2;
        }
    }
    ll ans = 1e18;
    FOR(i, sz(v_a)) {
        FOR(j, sz(v_b)) {
            ll x = v_a[i];
            ll y = v_b[j];
            if(x > y) {
                continue;
            }
            umin(ans, i + j + y - x);
        }
    }
    print(ans);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    read(t);
    for(int tc = 1; tc <= t; ++tc) {
        /* write("Case #", tc, ": "); */
        solve();
    }
    return 0;
}

