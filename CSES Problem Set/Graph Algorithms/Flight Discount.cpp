#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int mxN = 1e5 + 5;
int n, m;
ll dist1[mxN], dist2[mxN];
vector<pair<int, ll>> adj1[mxN], adj2[mxN];
bool vis1[mxN], vis2[mxN];

void go(int u, vector<pair<int, ll>> adj[mxN], ll dist[mxN], bool vis[mxN]) {
    memset(dist, 0x3f, sizeof(ll)*mxN);
    dist[u] = 0;
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
    pq.push({0, u});
    while(!pq.empty()) {
        int v = pq.top().second;
        pq.pop();
        if(vis[v])
            continue;
        vis[v] = 1;
        for(pair<int, ll> e : adj[v]) {
            int nv = e.first;
            ll w = e.second;
            if(dist[nv] > dist[v] + w) {
                dist[nv] = dist[v] + w;
                pq.push({dist[nv], nv});
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for(int i=0; i<m; ++i) {
        int a, b;
        ll c;
        cin >> a >> b >> c;
        adj1[a].push_back({b, c});
        adj2[b].push_back({a, c});
    }

    go(1, adj1, dist1, vis1);
    go(n, adj2, dist2, vis2);

    ll ans = 1e18;
    for(int i=1; i<=n; ++i) {
        /* cout << dist1[i] << " "; */
        for(pair<int, ll> e : adj1[i]) {
            ans = min(ans, dist1[i] + e.second/2 + dist2[e.first]);
        }
    }
    cout << ans;
    return 0;
}


