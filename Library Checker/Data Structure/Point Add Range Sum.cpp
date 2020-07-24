#include <bits/stdc++.h>
using namespace std;
using ll=long long;

const int mxN=5e5+1;
ll n, q, a[mxN], bit[mxN];

void upd(int i, int x) {
    for (++i; i<=n; i+=i&(-i))
        bit[i]+=x;
}

ll query(int i) {
    ll ans=0;
    for (++i; i>0; i-=i&(-i))
        ans+=bit[i];
    return ans;
}

ll query(int l, int r) {
    return query(r)-query(l-1);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> q;
    for (int i=0; i<n; ++i)
        cin >> a[i], upd(i, a[i]);
    while (q--) {
        int t, l, r;
        cin >> t >> l >> r;
        if (t)
            cout << query(l, r-1) << '\n';
        else
            upd(l, r);
    }
}
