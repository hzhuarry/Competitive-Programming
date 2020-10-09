#include <bits/stdc++.h>
using namespace std;

int N, a[2001], parent[2001];
vector<array<int,3>> v;

int find(int x) {
    return parent[x] == x ? x : parent[x] = find(parent[x]);
}

void merge(int a, int b) {
    a = find(a);
    b = find(b);
    if(a != b) {
        parent[b] = a;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ifstream cin("superbull.in");
    ofstream cout("superbull.out");

    cin >> N;
    for(int i=1; i<=N; ++i) {
        parent[i] = i;
        cin >> a[i];
    }

    for(int i=1; i<N; ++i) {
        for(int j=i+1; j<=N; ++j) {
            v.push_back({a[i]^a[j], i, j});
        }
    }
    sort(v.rbegin(), v.rend());
    
    long long res = 0;
    for(array<int,3> u : v) {
        int w = u[0], a = u[1], b = u[2];
        if(find(a) != find(b)) {
            merge(a, b);
            res += (long long)w;
        }
    }
    cout << res << endl;
    return 0;
}


