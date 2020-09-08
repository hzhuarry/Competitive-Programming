#include <bits/stdc++.h>
using namespace std;

const int MX = 2e5;
int n, m;
int parent[MX+1], sz[MX+1];
int cmp, large_cmp;

void init() {
    for(int i=1; i<=n; ++i) {
        parent[i] = i;
        sz[i] = 1;
    }
    cmp = n;
    large_cmp = 1;
}

int find(int x) {
    return parent[x]==x?x:parent[x]=find(parent[x]);
}

void merge(int a, int b) {
    a = find(a), b = find(b);
    if(a!=b) {
        parent[b] = a;
        sz[a] += sz[b];
        if(sz[a] > large_cmp) {
            large_cmp = sz[a];
        }
        --cmp;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    init();
    for(int i=0; i<m; ++i) {
        int a, b;
        cin >> a >> b;
        merge(a, b);
        cout << cmp << " " << large_cmp << endl;
    }
    return 0;
}

