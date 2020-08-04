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

str a,b;
int dp[3001][3001];

int main() {
    setIO();
    cin >> a >> b;
    int n = (int)a.size();
    int m = (int)b.size();
    for(int i=1;i<=n;++i){
        for(int j=1;j<=m;++j){
            if(a[i-1]==b[j-1]){
                dp[i][j] = dp[i-1][j-1] + 1;
            }
            else{
                dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
            }
        }
    }
    int sz = dp[n][m];
    if(sz==0)
        cout << "" << endl;
    else{
        str ans="";
        int i=n,j=m;
        while(i!=0 && j!=0){
            if(a[i-1]==b[j-1]){
                ans+=b[j-1];
                --i;
                --j;
            }
            else if(dp[i][j-1]>dp[i-1][j]){
                --j;
            }
            else{
                --i;
            }
        }
        reverse(ans.begin(),ans.end());
        cout << ans << endl;
    }
    return 0;
}
