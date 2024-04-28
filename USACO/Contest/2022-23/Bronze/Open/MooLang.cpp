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
#include <unordered_map>
#include <utility>
#include <vector>

using namespace std;

// TEMPLATE {{{

/* Macros */
#define finish(...) return void(print(__VA_ARGS__))

/* Input */
template<class T> void read(T &x) { cin >> x; }
template<class H, class T> void read(pair<H, T> &p) { read(p.first), read(p.second); }
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

// }}}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void run_case() {
    int n, C, P;
    read(n, C, P);
    vector<pair<string, string> > a(n);
    read(a);


    vector<string> nouns, trans, intrans, conjs;
    for (auto [word, type] : a) {
        if (type == "noun") {
            nouns.push_back(word);
        }
        else if (type == "transitive-verb") {
            trans.push_back(word);
        }
        else if (type == "intransitive-verb") {
            intrans.push_back(word);
        }
        else {
            conjs.push_back(word);
        }
    }


    int mx = 0;
    pair<int, int> verbs = {-1, -1};
    vector<string> TOPRINT;

    int m = nouns.size();
    for (int imx = 0; imx <= intrans.size(); ++imx) {
        if (m < imx) {
            continue;
        }
        int left = m - imx;
        for (int jmx = 0; jmx <= trans.size(); ++jmx) {
            int need = jmx * 2;
            if (left < need) {
                continue;
            }
            int unused = left - need;

            // find out total words 
            int total_sent = 0;
            if ((int) conjs.size() * 2 > imx + jmx) {
                total_sent = imx + jmx - (imx + jmx) / 2;
            }
            else {
                total_sent = imx + jmx - (int) conjs.size();
            }
            if (total_sent > P) continue;
            int tot_words = (2 * imx) + (3 * jmx) + conjs.size() + min(unused, C);
            if (mx < tot_words) {
                mx = tot_words;
                verbs = {imx, jmx};
            }
        }
    }

    vector<string> intra_sent, trans_sent;

    int ans = 0;
    int ni = 0;
    int c = C, p = P;
    {
        for (int i = 0; i < verbs.first and ni < nouns.size(); ++i) {
            string cur = nouns[ni++] + string(1, ' ') + intrans[i];
            intra_sent.push_back(cur);
        }
    }
    {
        for (int i = 0; i < verbs.second and ni < nouns.size(); ++i) {
            string cur = nouns[ni] + string(1, ' ') + trans[i] + string(1, ' ') + nouns[ni + 1];
            ni += 2;
            trans_sent.push_back(cur);
        }
    }
    while (not trans_sent.empty() and ni < nouns.size() and c > 0) {
        string ss = trans_sent.back();
        trans_sent.pop_back();
        ss += string(1, ',') + string(1, ' ') + nouns[ni++];
        trans_sent.push_back(ss);
        c -= 1;
    }

    int tot_sent_size = intra_sent.size() + trans_sent.size();
    int periods_needed = tot_sent_size - (int) conjs.size();
    int get_rid = max(0, periods_needed - p);

    vector<string> unused_nouns;

    while (ni < nouns.size()) {
        unused_nouns.push_back(nouns[ni++]);
    }

    while (c > 0 and not trans_sent.empty() and not unused_nouns.empty()) {
        string cur = trans_sent.back();
        trans_sent.pop_back();
        c -= 1;
        cur += string(1, ',') + string(1, ' ') + unused_nouns.back();
        unused_nouns.pop_back();
        trans_sent.push_back(cur);
    }

    vector<string> all;
    for (auto i : intra_sent) {
        all.push_back(i);
    }
    for (auto i : trans_sent) {
        all.push_back(i);
    }

    vector<string> merged;
    for (int i = 0; i < conjs.size(); ++i) {
        if ((int) all.size() < 2)
            break;
        string s = all.back();
        all.pop_back();
        string t = all.back();
        all.pop_back();
        string toadd = s + string(1, ' ') + conjs[i] + string(1, ' ') + t;
        merged.push_back(toadd);
    }
    for (auto i : merged) {
        all.push_back(i);
    }
    for (auto &i : all) {
        i.append(1, '.');
    }

    vector<pair<int, int> > order;
    for (int j = 0; j < all.size(); ++j) {
        string i = all[j];
        int cnt = 0;
        for (char c : i) {
            if (c == ',') {
                continue;
            }
            else if (c == ' ') {
                ++cnt;
            }
        }
        if (not i.empty()) {
            ++cnt;
        }
        order.push_back({cnt, j});
    }
    sort(order.rbegin(), order.rend());

    vector<string> toprint;
    for (int i = 0; i < min(p, (int) order.size()); ++i) {
        ans += order[i].first;
        toprint.push_back(all[order[i].second]);
    }
    print(ans);
    print(toprint);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    read(t);
    for (int tc = 1; tc <= t; ++tc) {
        run_case();
    }
}
