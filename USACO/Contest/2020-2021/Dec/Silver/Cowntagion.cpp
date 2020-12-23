#include <bits/stdc++.h>
using namespace std;

const int mxN=1e5+5;
int N, ans;
vector<int> adj[mxN];

void dfs(int v=1, int par=0) {
    int c=0;
    for(int nv : adj[v]) {
        if(nv==par)
            continue;
        ++c;
        dfs(nv, v);
    }
    int cur=1;
    while(cur<c+1) {
        cur*=2;
        ++ans;
    }
    ans+=c;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for(int i=1; i<N; ++i) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dfs();
    
    cout << ans << '\n';
    return 0;
}
