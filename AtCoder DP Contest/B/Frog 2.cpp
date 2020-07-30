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

int N,K;
ll a[100000];
ll dp[100000];

int main(){
    setIO();
    cin >> N >> K;
    for(int i=0;i<N;++i)
        cin >> a[i];
    for(int i=1;i<=K;++i){
        dp[i]=abs(a[i]-a[0]);
    }
    for(int i=K+1;i<N;++i){
        ll small=1e18;
        for(int j=i-1,cnt=0;cnt<K;--j,++cnt){
            small=min(small,abs(a[i]-a[j])+dp[j]);
        }
        dp[i]=small;
    }
    cout << dp[N-1] << endl;
    return 0;
}Frog 2
