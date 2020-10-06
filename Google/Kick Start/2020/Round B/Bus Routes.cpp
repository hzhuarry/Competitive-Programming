#include <bits/stdc++.h>
using namespace std;

#define ll long long

void solve() {
    ll N, D;
    cin >> N >> D;
    vector<ll> X(N);
    for(int i=0; i<N; ++i) {
        cin >> X[i];
    }

    for(int i=N-1; i>=0; --i) {
        D = (D/X[i]) * X[i];
    }
    
    cout << D << endl;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;
    for(int tc=1; tc<=T; ++tc) {
        cout << "Case #" << tc << ": ";
        solve();
    }
    return 0;
}


