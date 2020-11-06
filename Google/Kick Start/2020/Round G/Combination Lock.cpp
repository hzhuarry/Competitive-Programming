#include <bits/stdc++.h>
using namespace std;

#define ll long long

void solve() {
    ll W, N;
    cin >> W >> N;
    vector<ll> X(W);
    for(int i=0; i<W; ++i)
        cin >> X[i];

    for(int i=0; i<W; ++i) 
        X.push_back(X[i] + N);
    sort(X.begin(), X.end());

    int med_ind = W / 2, max_ind = W + W / 2;
    ll sum_less = 0, sum_greater = 0, num_less = med_ind, num_greater = W - med_ind - 1;

    for(int i=0; i<med_ind; ++i)
        sum_less += X[i];
    for(int i=med_ind+1; i<W; ++i)
        sum_greater += X[i];
    ll median = X[med_ind];

    ll res = (num_less*median - sum_less) + (sum_greater - num_greater*median);
    while(med_ind < max_ind) {
        sum_less -= X[med_ind-num_less];
        sum_less += median;
        sum_greater -= X[med_ind+1];
        median = X[++med_ind];
        sum_greater += X[med_ind + num_greater];
        res = min(res, (num_less*median - sum_less) + (sum_greater - num_greater*median));
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
