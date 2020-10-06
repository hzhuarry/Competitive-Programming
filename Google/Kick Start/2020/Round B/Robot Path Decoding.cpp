#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mod (ll)1e9

void solve() {
    string s;
    cin >> s;

    stack<ll> st;
    ll prod = 1;
    ll dx = 0, dy = 0;

    for(int i=0; i<(ll)s.size(); ++i) {
        if(s[i] == '(')
            continue;
        if(s[i] == 'N') {
            dx = (dx - prod) % mod;
        }
        else if(s[i] == 'S') {
            dx = (dx + prod) % mod;
        }
        else if(s[i] == 'E') {
            dy = (dy + prod) % mod;
        }
        else if(s[i] == 'W') {
            dy = (dy - prod) % mod;
        }
        else if(s[i] == ')'){
            prod = st.top();
            st.pop();
        }
        else {
            st.push(prod);
            prod = (prod * (s[i]-'0')) % mod;
        }
    }

    ll x = 1 + dx, y = 1 + dy;
    if(x <= 0) {
        x += (ll)1e9;
    }else if(x > (ll)1e9) {
        x -= (ll)1e9;
    }
    if(y <= 0) {
        y += (ll)1e9;
    }else if(y > (ll)1e9) {
        y -= (ll)1e9;
    }

    cout << y << " " << x << endl;
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


