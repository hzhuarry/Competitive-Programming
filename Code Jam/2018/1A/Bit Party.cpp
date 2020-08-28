#include <bits/stdc++.h>
using namespace std;

#define ll long long

const ll INF = 1e18+1e9;

bool ok(vector<array<ll,3>>&v, ll r, ll b, ll c, ll T) {
    vector<ll> poss;
    for(int i=0; i<c; ++i) {
        poss.push_back(max(min(v[i][0], (T-v[i][2])/v[i][1]), 0LL));
    }
    sort(poss.begin(), poss.end(), greater<int>());
    ll tot=0;
    for(int i=0; i<r; ++i) {
        tot += poss[i];
    }
    return tot >= b;
}

void solve() {
    ll r, b, c;
    cin >> r >> b >> c;
    vector<array<ll,3>> v(c);
    for(int i=0; i<c; ++i) {
        cin >> v[i][0] >> v[i][1] >> v[i][2];
    }

    ll lo=0, hi=INF;
    while(lo<hi) {
        ll mid = (lo+hi)/2;
        if(ok(v, r, b, c, mid))
            hi = mid;
        else
            lo = mid+1;
    }
    cout << lo << endl;
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    for(int tc=1; tc<=t; ++tc) {
        cout << "Case #" << tc << ": ";
        solve();
    }
    return 0;
}

