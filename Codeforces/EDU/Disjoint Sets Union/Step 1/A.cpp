#include <bits/stdc++.h>
using namespace std;

const int mx = 1e5+1;
int n, m;
int parent[mx];

void init() {
    for(int i=1; i<=n; ++i) {
        parent[i] = i;
    }
}

int find(int x) {
    return parent[x] == x ? x : parent[x] = find(parent[x]);
}

void merge(int u, int v) {
    u = find(u);
    v = find(v);
    if(u != v) {
        parent[u] = v;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    init();
    while(m--) {
        string str;
        int u, v;
        cin >> str >> u >> v;
        if(str == "union") {
            merge(u, v);
        }
        else {
            cout << (find(u) == find(v) ? "YES" : "NO") << endl;
        }
    }
    return 0;
}


