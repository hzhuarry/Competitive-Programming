#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int N, M, ans = 1e9;
ar<int, 2> cows[(int)1e5];
vector<int> adj[(int)1e5];
bool vis[(int)1e5];
int minX, minY, maxX, maxY;

void dfs(int u) {
    vis[u] = true;
    int x = cows[u][0];
    int y = cows[u][1];
    minX = min(minX, x);
    minY = min(minY, y);
    maxX = max(maxX, x);
    maxY = max(maxY, y);
    for(int nu : adj[u]) {
        if(!vis[nu]) {
            dfs(nu);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ifstream cin("fenceplan.in");
    ofstream cout("fenceplan.out");

    cin >> N >> M;
    for(int i = 0; i < N; ++i) {
        cin >> cows[i][0] >> cows[i][1];
    }
    for(int i = 0; i < M; ++i) {
        int x, y;
        cin >> x >> y;
        --x;
        --y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    
    for(int i = 0; i < N; ++i) {
        if(vis[i])
            continue;
        minX = minY = 1e9;
        maxX = maxY = 0;
        dfs(i);
        int perimeter = (2 * (maxY - minY)) + (2 * (maxX - minX));
        ans = min(ans, perimeter);
    }

    cout << ans << '\n';
}
