#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int MX = 1e5;
const ll MOD = 1e9+7;
int N;
vector<int> adj[MX];
/* 0=white, 1=black */
ll dp[MX][2];

void dfs(int v=0, int p=-1){
    ll sum1=1, sum2=1;
    for(int n : adj[v]){
        if(n==p)
            continue;
        dfs(n,v);
        sum1 *= dp[n][0]+ dp[n][1];
        sum1%=MOD;
        sum2 *= dp[n][0];
        sum2%=MOD;
    }
    dp[v][0] = sum1;
    dp[v][1] = sum2;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N;
    for(int i=0;i<N-1;++i){
        int a, b;
        cin >> a >> b;
        --a, --b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs();
    cout << (dp[0][0] + dp[0][1])%MOD << endl;
    return 0;
}
