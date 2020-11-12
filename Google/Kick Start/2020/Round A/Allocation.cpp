#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, b;
    cin >> n >> b;
    vector<int> a(n);
    for(int i=0; i<n; ++i)
        cin >> a[i];
    
    sort(a.begin(), a.end());
    int s=0, res=0;
    for(int i=0; i<n; ++i) {
        s += a[i];
        if(s > b)
            break;
        ++res;
    }
    cout << res << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;
    for(int tt=1; tt<=T; ++tt) {
        cout << "Case #" << tt << ": ";
        solve();
    }
    return 0;
}


