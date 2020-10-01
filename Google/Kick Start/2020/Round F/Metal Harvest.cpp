#include <bits/stdc++.h>
using namespace std;

#define ar array

void solve() {
    int N, K;
    cin >> N >> K;
    vector<ar<int,2>> intervals(N);
    vector<bool> vis(N, 0);
    for(int i=0; i<N; ++i) 
        cin >> intervals[i][0] >> intervals[i][1];
    sort(intervals.begin(), intervals.end());

    int res = 0, prev;
    for(int i=0; i<N; ++i) {
        if(i == 0) {
            int num = (intervals[i][1] - intervals[i][0] + K - 1)/K;
            res += num;
            prev = intervals[i][0] + num * K;
        }
        else {
            if(prev < intervals[i][0])
                prev = intervals[i][0];
            int num = (intervals[i][1] - prev + K - 1)/K;
            res += num;
            prev = prev + num * K;
        }
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


