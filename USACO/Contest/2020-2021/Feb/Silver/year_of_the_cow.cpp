#include <bits/stdc++.h>
using namespace std;

#define ll long long
const int mxN = 65536 + 1;
ll N, K, ancestors[mxN];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> K;
    for (int i = 0; i < N; ++i) {
        cin >> ancestors[i];
    }

    
    set<array<ll, 2> > st;

    for(int i = 0; i < N; ++i) {
        ll curY = ancestors[i];
        ll times = curY / 12;
        ll b1 = times * 12;
        ll b2 = (times + 1) * 12;
        st.insert({b1, b2});
    }

    ll ans = 0;
    vector<array<ll, 2> > a;

    for(auto x : st) {
        ans += x[1] - x[0];
        a.push_back(x);
    }

    vector<ll> dif;
    for(int i = 0; i < a.size(); ++i) {
        if(i == 0)
            dif.push_back(a[i][0]);
        else
            dif.push_back(a[i][0] - a[i - 1][1]);
    }
    sort(dif.begin(), dif.end());

    for(int i = 0; i < (ll)a.size() - K + 1; ++i) {
        ans += dif[i];
    }
    cout << ans << '\n';
}
