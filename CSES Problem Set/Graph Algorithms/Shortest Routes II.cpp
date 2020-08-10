#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define ll long long

const int MX=500;
const ll inf = 1e18;
int n, m, q;
ll dist[MX][MX];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> q;
    memset(dist, 0x3f, sizeof(dist));
    for(int i=0;i<n;++i){
        dist[i][i] = 0;
    }
    for(int i=0;i<m;++i){
        ll a, b, c;
        cin >> a >> b >> c;
        --a, --b;
        dist[a][b] = min(dist[a][b], c);
        dist[b][a] = min(dist[b][a], c);
    }
    for(int k=0; k<n; ++k){
        for(int i=0; i<n; ++i){
            for(int j=0; j<n; ++j){
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
    while(q--){
        int a, b;
        cin >> a >> b;
        --a, --b;
        cout << (dist[a][b]<inf?dist[a][b]:-1) << endl;
    }
    return 0;
}
