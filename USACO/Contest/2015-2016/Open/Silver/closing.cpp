#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> adj[3005];
bool vis[3005], closed[3005];

int dfs(int barn) {
    vis[barn] = true;
    int cnt = 1;
    for(int nextBarn : adj[barn]) {
        if(!vis[nextBarn] and !closed[nextBarn]) {
            cnt += dfs(nextBarn);
        }
    }
    return cnt;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ifstream cin("closing.in");
    ofstream cout("closing.out");

    cin >> n >> m;
    for(int i = 0; i < m; ++i) {
        int x, y;
        cin >> x >> y;
        --x;
        --y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    for(int cnt = 0; cnt < n; ++cnt) {
        memset(vis, 0, sizeof(vis));
        int barn;
        cin >> barn;
        --barn;
        int node = 0;
        for(int i = 0; i < n; ++i) {
            if(closed[i])
                continue;
            node = i;
            break;
        }
        int open = dfs(node);
        if(open != n - cnt)
            cout << "NO\n";
        else
            cout << "YES\n";

        closed[barn] = true;
    }
}
