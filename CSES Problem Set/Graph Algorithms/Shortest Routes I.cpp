#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back

const int MX = 1e5;
const ll inf = 1e18;
int n,m;
vector<pair<int,ll> > adj[MX];
ll dist[MX];
bool vis[MX];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for(int i=0;i<m;++i){
        int a,b;
        ll w;
        cin >> a >> b >> w;
        --a,--b;
        adj[a].pb({b,w});
    }
    fill(dist,dist+n,inf);
    dist[0]=0;

    priority_queue<pair<ll,int>, vector<pair<ll,int> > , greater<pair<ll,int> > > pq;
    pq.push({0,0});
    while(!pq.empty()){
        int v = pq.top().second;
        pq.pop();
        if(vis[v])
            continue;
        vis[v] = true;
        for(int i=0;i<(int)adj[v].size();++i){
            if(vis[adj[v][i].first])
                continue;
            int u = adj[v][i].first;
            ll d = adj[v][i].second;
            if(dist[v] + d < dist[u]){
                dist[u] = dist[v] + d;
                pq.push({dist[u],u});
            }
        }
    }
    for(int i=0;i<n;++i){
        cout << dist[i] << " ";
    }
    return 0;
}
