#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
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

const int maxn=2e5;
int n;
vector<int> adj[maxn+1];
/* 0 = do not include / 1 = include */
int dp[maxn+1][2];

void dfs(int v=1,int p=-1){
    for(int u : adj[v]){
        if(u == p)
            continue;
        dfs(u,v);
        /* if v's edge is not taken, then it is the max between the taken/untaken children */
        dp[v][0] += max(dp[u][0], dp[u][1]);
    }
    for(int u : adj[v]){
        if(u == p)
            continue;
        /* we take the edge to v */
        dp[v][1] = max(dp[v][1] , dp[u][0]+1+dp[v][0]-max(dp[u][0],dp[u][1]));
    }    
}

int main() {
    setIO();
    cin >> n;
    for(int i=1;i<n;++i){
        int a,b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs();
    cout << max(dp[1][0], dp[1][1]) << endl;
    return 0;
}
