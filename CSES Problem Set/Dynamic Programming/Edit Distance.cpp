#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define ar array
typedef long long ll;
typedef string str;

void setIO(string filename = "") {
    ios_base::sync_with_stdio(0); cin.tie(0);
    if ((int)filename.size()) {
        freopen((filename+".in").c_str(), "r", stdin);
        freopen((filename+".out").c_str(), "w", stdout);
    }
}

/* standard Levenshtein distance */

str a,b;
int dp[5001][5001];

int main() {
    setIO();
    cin >> a >> b;
    int n=(int)a.size(), m =(int)b.size();
    for(int j=1;j<=m;++j)
        dp[0][j]=j;
    for(int i=1;i<=n;++i)
        dp[i][0]=i;
    for(int i=1;i<=n;++i){
        for(int j=1;j<=m;++j){
            if(a[i-1]==b[j-1])
                dp[i][j] = dp[i-1][j-1];
            else
                dp[i][j]=1+min({dp[i-1][j],dp[i][j-1],dp[i-1][j-1]});
        }
    }
    cout << dp[n][m] << endl;
    return 0;
}
