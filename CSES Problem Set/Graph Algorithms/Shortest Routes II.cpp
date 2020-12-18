#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll n, m, q, dist[500][500];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> q;

    for(int i=0; i<n; ++i) {
        for(int j=0; j<n; ++j) {
            if(i == j) {
                dist[i][j] = 0;
            }
            else {
                dist[i][j] = (ll)1e18;
            }
        }
    }

    for(ll i=0; i<m; ++i) {
        ll a, b, c;
        cin >> a >> b >> c;
        --a;
        --b;
        dist[a][b] = min(dist[a][b], c);
        dist[b][a] = min(dist[b][a], c);
    }

    for(int k=0; k<n; ++k) {
        for(int i=0; i<n; ++i) {
            for(int j=0; j<n; ++j) {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }

    while(q--) {
        ll a, b;
        cin >> a >> b;
        --a;
        --b;
        cout << (dist[a][b] >= (ll)1e12 ? -1 : dist[a][b]) << '\n';
    }
    return 0;
}


