#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const ll INF=1e18;
const int maxn=1e6;

int n;
ll x;
ll coins[maxn];
ll dp[maxn+1];

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> x;
    for(int i=0;i<n;++i)
        cin >> coins[i];
    /* 0 coins to have a sum of 0 */
    for(int i=1;i<=x;++i){
       dp[i]=INF;
       for(int j=0;j<n;++j){
           if(i-coins[j]>=0){
               dp[i]=min(dp[i],dp[i-coins[j]]+1);
           }
       }
    }
    ll res=dp[x];
    if(res==INF) res=-1;
    cout << res << endl;
    return 0;
}
