#include <bits/stdc++.h>
using namespace std;

void solve() {
    int N;
    cin >> N;
    vector<int> H(N);
    for(int i=0; i<N; ++i)
        cin >> H[i];
    int res = 0;
    for(int i=1; i<N-1; ++i) {
        if(H[i] > H[i-1] and H[i] > H[i+1])
            ++res;
    }
    cout << res << endl;
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


