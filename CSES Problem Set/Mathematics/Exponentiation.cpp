#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
const ll mod = 1e9+7;
 
void solve() {
    ll a, b;
    cin >> a >> b;
    ll res = 1;
    while(b) {
        if(b&1)
            res = (res*a)%mod;
        a = (a*a)%mod;
        b >>= 1;
    }
    cout << res << "\n";
}
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
 
    int n;
    cin >> n;
    while(n--) 
        solve();
    return 0;
} 
