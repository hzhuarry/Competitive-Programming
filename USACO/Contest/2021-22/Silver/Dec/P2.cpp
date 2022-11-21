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
using ld = long double;

// }}}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void run_case() {
    int n, m;
    read(n, m);
    vt<vt<ll> > adj(n + 1);
    for(int i = 0; i < m; ++i) {
        ll x, y;
        read(x, y);
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    vt<vt<ll> > groups;
    vt<bool> vis(n + 1, false);
    int one_comp = -1, n_comp = n + 1;
    int color = 0;

    auto dfs = [&](auto &&self, int node, vt<ll>& comp) -> void {
        if(node == 1) {
            one_comp = color;
        }
        if(node == n) {
            n_comp = color;
        }
        vis[node] = true;
        comp.push_back(node);
        for(ll next : adj[node]) {
            if(!vis[next]) {
                self(self, next, comp);
            }
        }
    };

    for(int i = 1; i <= n; ++i) {
        if(!vis[i]) {
            vt<ll> nodes;
            dfs(dfs, i, nodes);
            color += 1;
            groups.push_back(nodes);
        }
    }

    if(one_comp == n_comp) {
        print(0);
    }
    else {
        for(auto &i : groups) {
            sort(all(i));
        }

        // first case is to use only one bridge
        ll ans = 1e18;
        for(ll &i : groups[one_comp]) {
            auto it = lower_bound(all(groups[n_comp]), i);
            if(it != groups[n_comp].end())
                ckmin(ans, (i - *it) * (i - *it));
            if(it != groups[n_comp].begin())
                --it;
            ckmin(ans, (i - *it) * (i - *it));
        }

        // second case is to use both bridges
        // the n_comp will try to connect with every other comp besides the first and we find the min
        // then we make the connection from the first comp
        ll ans2 = 1e18;
        for(int i = 0; i < sz(groups); ++i) {
            if(i == one_comp or i == n_comp) {
                continue;
            } 
            ll mn1 = 1e18, mn2 = 1e18;
            for(ll &u : groups[i]) {
                auto i1 = lower_bound(all(groups[one_comp]), u);
                if(i1 != groups[one_comp].end())
                    ckmin(mn1, (u - *i1) * (u - *i1));
                if(i1 != groups[one_comp].begin())
                    --i1;
                ckmin(mn1, (u - *i1) * (u - *i1));

                auto i2 = lower_bound(all(groups[n_comp]), u);
                if(i2 != groups[n_comp].end())
                    ckmin(mn2, (u - *i2) * (u - *i2));
                if(i2 != groups[n_comp].begin())
                    --i2;
                ckmin(mn2, (u - *i2) * (u - *i2));
                ckmin(ans2, mn1 + mn2);
            }
        }
        print(min(ans, ans2));
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    read(t);
    for(int tc = 1; tc <= t; ++tc) {
        // write("Case #", tc, ": ");
        run_case();
    }
}
