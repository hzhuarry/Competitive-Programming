#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <chrono>
#include <cmath>
#include <cstring>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <string>
#include <utility>
#include <vector>

using namespace std;

// TEMPLATE {{{

/* Macros */
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define ar array
#define vt vector
#define sz(x) (int)(x).size()
#define finish(...) return void(print(__VA_ARGS__))

/* Input */
template<class T> void read(T &x) { cin >> x; }
template<class H, class T> void read(pair<H, T> &p) { cin >> p.first >> p.second; }
template<class T, size_t S> void read(array<T, S> &a) { for (T &i : a) read(i); }
template<class T> void read(vector<T> &v) { for (T &i : v) read(i); }

template<class H, class... T> void read(H &h, T &...t) { read(h); read(t...); }

/* Output */
template<class H, class T> ostream &operator<<(ostream &o, pair<H, T> &p) { o << p.first << " " << p.second; return o; }
template<class T, size_t S> ostream &operator<<(ostream &o, array<T, S> &a) { string s; for (T i : a) o << s << i, s = " "; return o; }
template<class T> ostream &operator<<(ostream &o, vector<T> &v) { string s; for (T i : v) o << s << i, s = " "; return o; }

template<class H, class T> ostream &operator<<(ostream &o, vector<pair<H, T> > &v) { string s; for (auto& i : v) o << s << i, s = "\n"; return o; }
template<class T, size_t S> ostream &operator<<(ostream &o, vector<array<T, S> > &v) { string s; for (auto& i : v) o << s << i, s = "\n"; return o; }
template<class T> ostream &operator<<(ostream &o, vector<vector<T> > &v) { string s; for (auto& i : v) o << s << i, s = "\n"; return o; }

template<class T> void write(T x) { cout << x; }
template<class H, class... T> void write(const H &h, const T &...t) { write(h); write(t...); }

void print() { write('\n'); }
template<class H, class... T> void print(const H &h, const T &...t) { write(h); if (sizeof...(t)) write(' '); print(t...); }

/* Debug */
void DBG() { cerr << "]" << '\n'; }
template<class H, class... T> void DBG(H h, T... t) { cerr << h; if(sizeof...(t)) cerr << ", "; DBG(t...); }
#ifdef local
#define dbg(...) cerr << "LINE(" << __LINE__ << ") -> [" << #__VA_ARGS__ << "]: [", DBG(__VA_ARGS__)
#else
#define dbg(...) 0
#endif

template<typename X, typename Y> bool ckmin(X& x, const Y& y) { return (y < x) ? (x = y, 1) : 0; }
template<typename X, typename Y> bool ckmax(X& x, const Y& y) { return (x < y) ? (x = y, 1) : 0; }

using ll = long long;

// }}}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void run_case() {
    int K, M, N;
    read(K, M, N);
    vt<pair<ll, ll> > grass(K);
    read(grass);
    vt<ll> bad_pos(M);
    read(bad_pos);

    sort(all(grass));
    sort(all(bad_pos));

    vt<vt<ll> > contribution(M, vt<ll>(2, 0));
    for(int i = 0; i < K; ++i) {
        auto [pos, delta] = grass[i];
        auto it = lower_bound(all(bad_pos), pos);
        int mnIdx1 = -1, mnIdx2 = -1;
        if(it != bad_pos.end()) {
            mnIdx1 = it - bad_pos.begin();
        }
        if(it != bad_pos.begin()) {
            --it;
            mnIdx2 = it - bad_pos.begin();
        }
        ll d1 = ~mnIdx1 ? abs(bad_pos[mnIdx1] - pos) : 2e18;
        ll d2 = ~mnIdx2 ? abs(bad_pos[mnIdx2] - pos) : 2e18;
        assert(d1 < ll(2e18) or d2 < ll(2e18));
        if(d1 < d2) {
            if(bad_pos[mnIdx1] < pos) {
                contribution[mnIdx1][1] += delta;
            }
            else {
                contribution[mnIdx1][0] += delta;
            }
        }
        else {
            if(bad_pos[mnIdx2] < pos) {
                contribution[mnIdx2][1] += delta;
            }
            else {
                contribution[mnIdx2][0] += delta;
            }
        }
    }
    dbg(contribution);
    vt<ll> p;
    for(int i = 0; i < M; ++i) {
        p.push_back(contribution[i][0]);
        p.push_back(contribution[i][1]);
    }
    sort(rall(p));
    ll ans = 0;
    for(int i = 0; i < N; ++i) {
        ans += p[i];
    }
    print(ans);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    // read(t);
    for(int tc = 1; tc <= t; ++tc) {
        run_case();
    }
}

