#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll res;
int n, m, parent[100001], sz[100001];
vector<array<int,3>> edgeList;

int find(int x) {
    return parent[x] == x ? x : parent[x] = find(parent[x]);
}

void merge(int a, int b) {
    a = find(a);
    b = find(b);
    if(a != b) {
        parent[b] = a;
        sz[a] += sz[b];
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    for(int i=1; i<=n; ++i) {
        parent[i] = i;
        sz[i] = 1;
    }

    for(int i=0; i<m; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        edgeList.push_back({c, a, b});
    }
    sort(edgeList.begin(), edgeList.end());

    for(array<int,3> edge : edgeList) {
        int w = edge[0], a = edge[1], b = edge[2];
        if(find(a) != find(b)) {
            res += w;
            merge(a, b);
        }
    }
    
    if(sz[find(1)] == n) {
        cout << res << endl;
    }
    else {
        cout << "IMPOSSIBLE" << endl;
    }
    return 0;
}
