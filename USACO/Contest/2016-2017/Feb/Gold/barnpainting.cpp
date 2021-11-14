#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define MOD (ll)(1e9 + 7)

int n, k;
vector<int> adj[(int)1e5];
ll dp[(int)1e5][3];
int color[(int)1e5];

void dfs(int v = 0, int par = -1) {
    ll s1 = 0;
    ll s2 = 0;
    ll s3 = 0;
    int c = color[v];
    if(color[v] == -1) {
        s1 = s2 = s3 = 1;
    } 
    else {
        if(c == 0)
            s1 = 1;
        else if(c == 1)
            s2 = 1;
        else
            s3 = 1;
    }
    for(int nv : adj[v]) {
        if(nv == par)
            continue;
        dfs(nv, v);
    }

    for(int nv : adj[v]) {
        if(nv == par)
            continue;
        s1 *= (dp[nv][1] + dp[nv][2]);
        s1 %= MOD;
        s2 *= (dp[nv][0] + dp[nv][2]);
        s2 %= MOD;
        s3 *= (dp[nv][0] + dp[nv][1]);
        s3 %= MOD;
    }
    dp[v][0] = s1;
    dp[v][1] = s2;
    dp[v][2] = s3;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ifstream cin("barnpainting.in");
    ofstream cout("barnpainting.out");

    cin >> n >> k;
    for(int i = 0; i < n - 1; ++i) {
        int x, y;
        cin >> x >> y;
        --x;
        --y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    memset(color, -1, sizeof(color));
    for(int i = 0; i < k; ++i) {
        int b, c;
        cin >> b >> c;
        --b;
        --c;
        color[b] = c;
    }
    dfs();
    cout << (dp[0][0] + dp[0][1] + dp[0][2]) % MOD << '\n';
}


