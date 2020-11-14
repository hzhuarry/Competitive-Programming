/*
ID: hzhu7271
LANG: C++
TASK: subset 
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ifstream cin("subset.in");
    ofstream cout("subset.out");

    int N;
    cin >> N;
    int sum = (N*(N+1))/2;
    if(sum & 1) {
        return cout << "0\n", 0;
    }

    int dp[N+1][sum+1];
    memset(dp, 0, sizeof(dp));
    dp[0][0] = 1;
    for(int i=1; i<N; ++i) {
        for(int j=0; j<=sum/2; ++j) {
            dp[i][j] = dp[i-1][j];
            if(j - i >= 0) {
                dp[i][j] += dp[i-1][j-i];
            }
        }
    }
    cout << dp[N-1][sum/2] << endl;
    return 0;
}

