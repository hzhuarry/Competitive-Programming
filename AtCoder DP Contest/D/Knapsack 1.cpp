#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define pb push_back
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

ll N,W;
ll w[101],v[101];
/* weight/value */
ll dp[101][100001];

int main() {
    setIO();
    cin >> N >> W;
    for(int i=1;i<=N;++i){
        cin >> w[i] >> v[i];
    }
    for(int i=1;i<=N;++i){
        ll weight=w[i], val=v[i];
        for(int j=1;j<=W;++j){
            dp[i][j]=dp[i-1][j];
            if(j>=weight && dp[i-1][j-weight]+val > dp[i][j]){
                dp[i][j] = dp[i-1][j-weight] + val;
            }
        }
    }
    cout << dp[N][W] << endl;
    return 0;
}

