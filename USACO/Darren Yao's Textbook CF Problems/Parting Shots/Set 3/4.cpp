#include <bits/stdc++.h>
using namespace std;

const int inf = 1e9;

void solve(){
    int n;
    cin >> n;
    int minx = -inf, miny = -inf, maxx = inf, maxy = inf;
    int x, y, a, b, c, d;
    while(n--){
        cin >> x >> y >> a >> b >> c >> d;
        if(a==0)
            minx = max(minx, x);
        if(b==0)
            maxy = min(maxy, y);
        if(c==0)
            maxx = min(maxx, x);
        if(d==0)
            miny = max(miny, y);
    }
    if(minx<=maxx and miny<=maxy){
        cout << 1 << " ";
        int ansx = minx == -inf ? (maxx == inf ? x : maxx) : minx;
        int ansy = miny == -inf ? (maxy == inf ? y : maxy) : miny;
        cout << ansx << " " << ansy << endl;
    }
    else
        cout << 0 << endl;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int q;
    cin >> q;
    while(q--)
        solve();
    return 0;
}
