#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
start:
    while(t--) {
        int n;
        cin >> n;
        vector<ll> v(n);
        for(int i=0; i<n; ++i) {
            cin >> v[i];
        }
        sort(v.begin(), v.end());
        ll poss = v.front() * v.back();
        vector<ll> d;
        for(ll i=2; i*i<=poss; ++i) {
            if(poss%i)
                continue;
            d.push_back(i);
            if(i != poss/i)
                d.push_back(poss/i);
        }
        sort(d.begin(), d.end());
        if(d.size() != n) {
            cout << -1 << endl;
            goto start;
        }
        for(int i=0; i<n; ++i) {
            if(d[i] != v[i]) {
                cout << -1 << endl;
                goto start;
            }
        }
        cout << poss << endl;
    }
    return 0;
}


