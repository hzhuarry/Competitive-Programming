#include <bits/stdc++.h>
using namespace std;

string s1, s2;
int dp[5005][5005];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> s1 >> s2;

    memset(dp, 0x3f, sizeof(dp));
    dp[0][0] = 0;
    for(int i=0; i<=s1.size(); ++i) {
        for(int j=0; j<=s2.size(); ++j) {
            /* delete char s1[i-1] */
            if(i)
                dp[i][j] = min(dp[i][j], dp[i-1][j] + 1);
            /* add char s2[j-1] at the end of s1[i] */
            if(j)
                dp[i][j] = min(dp[i][j], dp[i][j-1] + 1);
            /* replace s1[i-1] with s2[j-1] */
            if(i and j)
                dp[i][j] = min(dp[i][j], dp[i-1][j-1] + (s1[i-1] != s2[j-1]));
        }
    }

    cout << dp[s1.size()][s2.size()];
    return 0;
}


