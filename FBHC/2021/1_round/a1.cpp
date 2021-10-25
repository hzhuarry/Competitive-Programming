#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    string ss;
    cin >> ss;

    int lastInd = -1;
    int ans = 0;
    for(int i = 0; i < n; ++i) {
        if(ss[i] == 'F')
            continue;
        if(lastInd == -1) {
            lastInd = i;
            continue;
        }
        if(ss[i] != ss[lastInd]) {
            ans++;
        }
        lastInd = i;
    }
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    for(int i = 1; i <= t; ++i) {
        cout << "Case #" << i << ": ";
        solve();
    }
}

