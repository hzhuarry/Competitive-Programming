#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int MXN = 2e5 + 5;
int n;
array<ll, 3> a[MXN];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
 
    cin >> n;
    for(int i=0; i<n; ++i) {
        cin >> a[i][1] >> a[i][0] >> a[i][2];
    }

    /* sort by ending time */
    sort(a, a+n);

    /* {endtime, total value} */
    set<array<ll, 2>> dp;
    dp.insert({0, 0});
    ll last_dp = 0;

    for(int i=0; i<n; ++i) {
        auto j = dp.lower_bound({a[i][1], 0});
        --j;
        last_dp = max(last_dp, a[i][2] + (*j)[1]);
        dp.insert({a[i][0], last_dp});
    }

    cout << last_dp;
    return 0;
} 
