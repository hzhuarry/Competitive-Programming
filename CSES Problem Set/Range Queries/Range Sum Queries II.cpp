#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int mxn = 2e5 + 5;
ll n, q, x[mxn], bit[mxn];

void upd(int pos, ll delta) {
    for(int i = pos; i <= n; i += (i & -i)) {
        bit[i] += delta;
    }
}

ll go(int pos) {
    ll sum = 0;
    for(int i = pos; i > 0; i -= (i & -i)) {
        sum += bit[i];
    }
    return sum;
}

ll sum(int a, int b) {
    return go(b) - go(a - 1);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> q;
    for(int i = 1; i <= n; ++i) {
        cin >> x[i];
        upd(i, x[i]);
    }

    while(q--) {
        int t, a, b;
        cin >> t >> a >> b;
        if(t == 1) {
            upd(a, b - x[a]);
            x[a] = b;
        }
        else {
            cout << sum(a, b) << '\n';
        }
    }
    return 0;
}


