#include <bits/stdc++.h>
using namespace std;
 
int n, x[200005];
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
 
    cin >> n;
    for(int i=0; i<n; ++i)
        cin >> x[i];

    vector<int> dp;
    for(int i=0; i<n; ++i) {
        /* To find the longest increasing subsequence where we allow consecutive equal values (for example 1,2,2,3), change lower_bound to upper_bound. */
        auto it = lower_bound(dp.begin(), dp.end(), x[i]);
        if(it==dp.end())
            dp.push_back(x[i]);
        else
            *it=x[i];
    }
    cout << dp.size();
    return 0;
} 
