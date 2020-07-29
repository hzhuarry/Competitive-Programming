#include <bits/stdc++.h>

using namespace std;
#define pb push_back
#define all(x) x.begin(),x.end()
using ll = long long;

/* FILE IO */
void setIO(string filename = "") {
    ios_base::sync_with_stdio(0); cin.tie(0);
    if ((int)filename.size()) { /* USACO */
        freopen((filename+".in").c_str(), "r", stdin);
        freopen((filename+".out").c_str(), "w", stdout);
    }
}

const ll MOD=1e9+7;
int n,x;
int c[100];
ll dp[1000001];

int main(){
    setIO();
    cin >> n >> x;
    for(int i=0;i<n;++i)
        cin >> c[i];
    dp[0]=1;
    for(int i=1;i<=x;++i){
        for(int j=0;j<n;++j){
            if(i-c[j]>=0){
                dp[i]+=dp[i-c[j]];
                dp[i]%=MOD;
            }
        }
    }
    cout << dp[x] << endl;
    return 0;
}
