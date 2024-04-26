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
#include <string>
#include <unordered_map>
#include <utility>
#include <vector>

using namespace std;

// TEMPLATE {{{

/* Macros */
#define finish(...) return void(print(__VA_ARGS__))

/* Input */
template<class T> void read(T &x) { cin >> x; }
template<class T, size_t S> void read(array<T, S> &a) { for (T &i : a) read(i); }
template<class H, class T> void read(pair<H, T> &p) { read(p.first), read(p.second); }
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
// }}}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void run_case() {
    freopen("bcs.in", "r", stdin);
    freopen("bcs.out", "w", stdout);
    int n, k;
    read(n, k);
    vector<vector<char> > og(n, vector<char>(n));
    read(og);
    vector<vector<vector<char> > > pos(k, vector<vector<char> >(n, vector<char>(n)));
    read(pos);

    int COUNT = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            COUNT += og[i][j] == '#';
        }
    }

    auto go_down = [] (vector<vector<char> > grid) -> vector<vector<char> > {
        int n = grid.size();
        vector<vector<char> > ret(n, vector<char>(n, '.')); int mxshift = n - 1;
        for (int j = 0; j < n; ++j) {
            int shift_dist = 0;
            for (int i = n - 1; i >= 0; --i) {
                if (grid[i][j] == '#') {
                    break;
                }
                ++shift_dist;
            }
            mxshift = min(mxshift, shift_dist);
        }
        for (int j = 0; j < n; ++j) {
            for (int i = n - 1; i >= 0; --i) {
                if (i + mxshift < n) {
                    ret[i + mxshift][j] = grid[i][j];
                }
            }
        }
        return ret;
    };
    auto go_up = [] (vector<vector<char> > grid) -> vector<vector<char> > {
        int n = grid.size();
        vector<vector<char> > ret(n, vector<char>(n, '.'));
        int mxshift = n - 1;
        for (int j = 0; j < n; ++j) {
            int shift_dist = 0;
            for (int i = 0; i < n; ++i) {
                if (grid[i][j] == '#') {
                    break;
                }
                ++shift_dist;
            }
            mxshift = min(mxshift, shift_dist);
        }
        for (int j = 0; j < n; ++j) {
            for (int i = 0; i < n; ++i) {
                if (i - mxshift >= 0) {
                    ret[i - mxshift][j] = grid[i][j];
                }
            }
        }
        return ret;
    };
    auto go_right = [] (vector<vector<char> > grid) -> vector<vector<char> > {
        int n = grid.size();
        vector<vector<char> > ret(n, vector<char>(n, '.'));
        int mxshift = n - 1;
        for (int i = 0; i < n; ++i) {
            int shift_dist = 0;
            for (int j = n - 1; j >= 0; --j) {
                if (grid[i][j] == '#') {
                    break;
                }
                ++shift_dist;
            }
            mxshift = min(mxshift, shift_dist);
        }
        for (int i = 0; i < n; ++i) {
            for (int j = n - 1; j >= 0; --j) {
                if (j + mxshift < n) {
                    ret[i][j + mxshift] = grid[i][j]; 
                }
            }
        }
        return ret;
    };
    auto go_left = [] (vector<vector<char> > grid) -> vector<vector<char> > {
        int n = grid.size();
        vector<vector<char> > ret(n, vector<char>(n, '.'));
        int mxshift = n - 1;
        for (int i = 0; i < n; ++i) {
            int shift_dist = 0;
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == '#') {
                    break;
                }
                ++shift_dist;
            }
            mxshift = min(mxshift, shift_dist);
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (j - mxshift >= 0) {
                    ret[i][j - mxshift] = grid[i][j]; 
                }
            }
        }
        return ret;
    };
    auto go_top_left = [&] (vector<vector<char> > grid) -> vector<vector<char> > {
        return go_left(go_up(grid));
    };
    auto go_bot_right = [&] (vector<vector<char> > grid) -> vector<vector<char> > {
        return go_down(go_right(grid));
    };

    vector<vector<vector<char> > > topleft(k), botright(k);
    for (int i = 0; i < k; ++i) {
        vector<vector<char> > cur = pos[i];
        topleft[i] = go_up(go_left(cur));
        botright[i] = go_down(go_right(cur));
    }


    vector<pair<int, int> > ans;
    for (int i = 0; i < k; ++i) {
        for (int j = 0; j < k; ++j) {
            if (i == j)
                continue;
            int mn = min(i, j) + 1, mx = max(i, j) + 1;


            auto a = go_top_left(og);
            auto x = topleft[i], y = botright[j];
            int count = 0;
            bool ok = true;
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                    if (x[i][j] == '#' and a[i][j] == '.') {
                        ok = false;
                        break;
                    }
                    count += x[i][j] == '#';
                    if (x[i][j] == '#')
                        a[i][j] = '.';
                }
            }
            auto b = go_bot_right(a);
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                    if (y[i][j] == '#' and b[i][j] == '.') {
                        ok = false;
                        break;
                    }
                    count += y[i][j] == '#';
                    if (y[i][j] == '#')
                        b[i][j] = '.';
                }
            }
            int left = 0;
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                    left += b[i][j] == '#';
                }
            }
            if (ok and (count == COUNT) and (left == 0)) {
                finish(mn, mx);
            }
        }
    }
    assert(false);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    for (int tc = 1; tc <= t; ++tc) {
        run_case();
    }
}
