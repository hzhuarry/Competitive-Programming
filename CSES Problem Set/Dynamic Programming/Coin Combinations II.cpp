#include <bits/stdc++.h>

using namespace std;
using ll = long long;

/* FILE IO */
void setIO(string filename = "") {
    ios_base::sync_with_stdio(0); cin.tie(0);
    if ((int)filename.size()) { /* USACO */
        freopen((filename+".in").c_str(), "r", stdin);
        freopen((filename+".out").c_str(), "w", stdout);
    }
}

const int maxn=1e6;
const ll MOD=1e9+7;
int n;
ll x;
ll coins[100];
ll dp[maxn+1];

int main(){
    setIO();
    cin >> n >> x;
    for(int i=0;i<n;++i){
        cin >> coins[i];
    }
    dp[0]=1;
    for(int i=0;i<n;++i){
        for(int j=1;j<=x;++j){
            if(j-coins[i]>=0){
                dp[j]+=dp[j-coins[i]];
                dp[j]%=MOD;
            }
        }
    }
    cout << dp[x] << endl;
    return 0;
}
