#include <bits/stdc++.h>
using namespace std;

const int MX = 1e5;
int n, m;
vector<int> adj[MX][2];
bool vis[MX];

void dfs(int f, int v=0) {
    vis[v] = 1;
    for(int u : adj[v][f]){
        if(vis[u])
            continue;
        dfs(f, u);
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for(int i=0; i<m; ++i) {
        int a, b;
        cin >> a >> b;
        --a, --b;
        adj[a][0].push_back(b);
        adj[b][1].push_back(a);
    }

    dfs(0);
    for(int i=0; i<n; ++i) {
        if(!vis[i]){
            cout << "NO" << endl;
            cout << 1 << " " << i+1 << endl;
            return 0;
        }
    }

    fill(vis, vis+n, false);

    dfs(1);
    for(int i=0; i<n; ++i) {
        if(!vis[i]){
            cout << "NO" << endl;
            cout << i+1 << " " << 1 << endl;
            return 0;
        }
    }

    cout << "YES" << endl;
    return 0;
}

