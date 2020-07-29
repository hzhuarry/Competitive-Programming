#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int maxn=1e5;
int N;
int a[maxn];
int dp[maxn];

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin >> N;
    for(int i=0;i<N;++i){
        cin >> a[i];
    }
    dp[1] = abs(a[1]-a[0]);
    for(int i=2;i<N;++i){
        dp[i]=min(dp[i-1]+abs(a[i]-a[i-1]),dp[i-2]+abs(a[i]-a[i-2]));
    }
    cout << dp[N-1] << endl;
    return 0;
}
