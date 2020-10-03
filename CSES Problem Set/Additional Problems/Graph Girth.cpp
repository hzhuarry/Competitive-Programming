#include <bits/stdc++.h>
using namespace std;

const int MX = 2501;
int n, m, res = MX;
vector<int> adj[MX];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for(int i=0; i<m; ++i) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    for(int i=1; i<=n; ++i) {
        vector<int> dist(n+1, (int)1e9);
        vector<int> par(n+1, -1);

        dist[i] = 0;
        queue<int> q;
        q.push(i);

        while(!q.empty()) {
            int v = q.front();
            q.pop();

            for(int u : adj[v]) {
                if(dist[u] == (int)1e9) {
                    dist[u] = dist[v] + 1;
                    par[u] = v;
                    q.push(u);
                }
                else if(par[v] != u and par[u] != v) {
                    res = min(res, dist[v] + dist[u] + 1);
                }
            }
        }
    }

    if(res > 2500)
        cout << -1 << endl;
    else
        cout << res << endl;
    return 0;
}


