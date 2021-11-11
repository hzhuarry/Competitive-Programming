#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int n;
vector<int> adj[(int)2e5];
int dp[(int)2e5][2]; //unused = 0, used = 1,

void dfs(int node = 0, int parent = -1) {
    for(int child: adj[node]) {
        if(child == parent)
            continue;
        dfs(child, node);
    }

    for(int child: adj[node]) {
        if(child == parent)
            continue;
        dp[node][0] += dp[child][1];
    }
    
    for(int child: adj[node]) {
        if(child == parent)
            continue;
        dp[node][1] = max(dp[node][1], dp[node][0] - dp[child][1] + dp[child][0] + 1);
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(int i = 0; i < n - 1; ++i) {
        int x, y;
        cin >> x >> y;
        --x;
        --y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    dfs();

    cout << max(dp[0][0], dp[0][1]);
}

