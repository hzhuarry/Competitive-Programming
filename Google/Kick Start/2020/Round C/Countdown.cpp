#include <bits/stdc++.h>
using namespace std;

void solve() {
    int N, K, res = 0;
    cin >> N >> K;
    vector<int> A(N);
    for(int i=0; i<N; ++i)
        cin >> A[i];
    for(int i=0; i<N; ) {
        if(A[i] != K) {
            ++i;
            continue;
        }
        bool f = 1;
        int k = K;
        for(; i<N and k>=1; ++i, --k) {
            if(A[i] != k) {
                f = 0;
                break;
            }
        }
        if(f and k==0)
            ++res;
    }
    cout << res << endl;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;
    for(int tc=1; tc<= T; ++tc) {
        cout << "Case #" << tc << ": ";
        solve();
    }
    return 0;
}


