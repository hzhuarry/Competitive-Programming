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

const ll INF=1e18;
int n;
ll dp[1000001];

vector<ll> get_dig(ll x){
    vector<ll> res;
    while(x){
        res.pb(x%10);
        x/=10;
    }
    return res;
}

int main(){
    setIO();
    cin >> n;
    fill(dp,dp+n+1,INF);
    dp[n]=0;
    for(int i=n;i>=0;--i){
        vector<ll> digits = get_dig(i);
        for(ll x:digits){
            if(i-x>=0){
                dp[i-x]=min(dp[i]+1,dp[i-x]);
            }
        }
    }
    cout << dp[0] << endl;
    return 0;
}
