#include <bits/stdc++.h>
using namespace std;

int n, x[100];
bool dp[101][100001];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(int i=0; i<n; ++i)
        cin >> x[i];

    dp[0][0] = 1;
    for(int i=1; i<=n; ++i) {
        for(int cost=0; cost<=1000*n; ++cost) {
            dp[i][cost] = dp[i-1][cost];
            if(cost - x[i-1] >= 0 and dp[i-1][cost - x[i-1]]) {
                dp[i][cost] = 1;
            }
        }
    }
    
    vector<int> res;
    for(int i=1; i<1000*n; ++i)
        if(dp[n][i])
            res.push_back(i);

    cout << res.size() << endl;
    for(int x : res)
        cout << x << " ";
    return 0;
}


