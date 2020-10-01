#include <bits/stdc++.h>
using namespace std;

#define ar array

void solve() {
    int N, X;
    cin >> N >> X;
    vector<int> A(N);
    for(int i=0; i<N; ++i) {
        cin >> A[i];
    }
    vector<ar<int,2>> order;
    for(int i=0; i<N; ++i) {
        order.push_back({(A[i]+X-1)/X, i});
    }
    sort(order.begin(), order.end());
    assert(order.size() == N);
    for(int i=0; i<N; ++i) {
        cout << order[i][1] + 1 << " ";
    }
    cout << endl;
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


