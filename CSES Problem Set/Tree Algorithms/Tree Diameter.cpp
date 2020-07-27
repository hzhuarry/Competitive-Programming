#include <bits/stdc++.h>

using namespace std;

#define pb push_back

const int maxn=2e5 + 1;

int N;
vector<int> adj[maxn];
int dist[maxn];

void dfs(int node=1,int parent=0){
    if(parent>0)
        dist[node] = dist[parent]+1;
    for(int neighbor : adj[node]){
        if(parent!=neighbor){
            dfs(neighbor,node);
        }
    }
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin >> N;
    for(int i=1;i<N;++i){
        int a,b;
        cin >> a >> b;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    dfs();
    int far_node1 = max_element(dist+1,dist+N+1) - dist;
    memset(dist,0,sizeof(dist));
    dfs(far_node1);
    cout << *max_element(dist+1,dist+1+N) << endl;
    return 0;
}
