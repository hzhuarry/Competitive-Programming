#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array
#define vt vector

const int maxn=1e5;
const ll MX = 1e18;
int N,T;
ar<ll,2> a[maxn];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ifstream cin("cowjog.in");
    ofstream cout("cowjog.out");
    cin >> N >> T;
    for(int i=0;i<N;++i){
        cin >> a[i][0] >> a[i][1];
    }
    vt<ll> newpos;
    for(int i=0;i<N;++i){
        ll pos = a[i][0] + ((ll)T * a[i][1]);
        newpos.push_back(pos);
    }
    vt<ll> dp(N+1,-MX);
    dp[0]=MX;
    for(int i=0;i<N;++i){
        int j = upper_bound(dp.begin(), dp.end(), newpos[i], greater<ll>()) - dp.begin();
        if(dp[j-1] >= newpos[i] and newpos[i] >= dp[j]){
            dp[j] = newpos[i];
        }
    }
    int res = 0;
    for(int i=0;i<=N;++i)
        if(dp[i] > -MX)
            res = i;
    cout << res << endl;
}
