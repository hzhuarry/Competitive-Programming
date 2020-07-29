#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const ll MOD=1e9+7;
const int maxn=1e6;

ll n;
ll dp[maxn+1];
ll dice[6] = {1,2,3,4,5,6};

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    dp[0]=1;
    for(int i=1;i<=n;++i){
        for(int c:dice){
            if(i-c >=0){
                dp[i]=(dp[i] + dp[i-c])%MOD;
            }
        }
    }
    cout << dp[n] << endl;
    return 0;
}
