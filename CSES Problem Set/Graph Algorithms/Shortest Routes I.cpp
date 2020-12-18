#include <bits/stdc++.h>
using namespace std;

#define ll long long

const ll MXN = 1e5 + 5;
ll n, m, dist[MXN];
bool vis[MXN];
vector<array<ll, 2>> adj[MXN];
priority_queue<array<ll, 2>, vector<array<ll, 2>>, greater<array<ll, 2>>> pq;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for(int i=0; i<m; ++i) {
        ll a, b, c;
        cin >> a >> b >> c;
        --a;
        --b;
        adj[a].push_back({b, c});
    }

    memset(dist, 0x3f, sizeof(dist));
    dist[0] = 0;
    pq.push({0, 0});

    while(!pq.empty()) {
        ll v = pq.top()[1];
        pq.pop();
        if(vis[v])
            continue;
        vis[v] = 1;
        for(auto u : adj[v]) {
            if(dist[v] + u[1] < dist[u[0]]) {
                dist[u[0]] = dist[v] + u[1];
                pq.push({dist[u[0]], u[0]});
            }
        }
    }

    for(int i=0; i<n; ++i)
        cout << dist[i] << " ";
    return 0;
}


