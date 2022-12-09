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
    int n;
    read(n);
    vector<int> a(n);
    read(a);

    vector<int> possible(int(1e5) + 5, 0);
    possible[0] = 1;
    set<int> ans;
    for(int &coin : a) {
        for(int i = int(1e5); i >= 1; --i) {
            if(i - coin >= 0) {
                possible[i] |= possible[i - coin];
                if(possible[i])
                    ans.insert(i);
            }
        }
    }
    print(sz(ans));
    for(int i : ans)
        write(i, ' ');
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // read(t);
    for(int tc = 1; tc <= t; ++tc) {
        run_case();
    }
}
