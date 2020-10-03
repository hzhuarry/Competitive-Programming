#include <bits/stdc++.h>
using namespace std;

void solve() {
    int N;
    cin >> N;
    vector<int> A(N);
    for(int i=0; i<N; ++i) 
        cin >> A[i];
    int k; 
    int res = 2, cnt = 2;
    for(int i=1; i<N; ++i) {
        if(i == 1) {
            k = A[i] - A[i-1];
        }
        else {
            int dif = A[i] - A[i-1];
            if(dif == k) {
                ++cnt;
            }
            else {
                cnt = 2;
                k = dif;
            }
        }
        res = max(res, cnt);
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


