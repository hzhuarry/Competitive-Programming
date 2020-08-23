#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

/* sort by y-val */
bool cmp(const ar<ll,2>& a, const ar<ll,2>& b){
    if(a[1] == b[1])
        return a[0] < b[0];
    return a[1] < b[1];
}

const int MX = 5e4;
const ll inf = 1e18;
int N;
ar<ll,2> cows[MX];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ifstream cin("split.in");
    ofstream cout("split.out");

    cin >> N;
    for(int i=0; i<N; ++i)
        cin >> cows[i][0] >> cows[i][1];
    
    /* vertical split */
    sort(cows, cows+N);
    ll miny=inf, maxy=1;
    for(int i=0; i<N; ++i){
        miny = min(miny, cows[i][1]);
        maxy = max(maxy, cows[i][1]);
    }
    ll tot = (cows[N-1][0]-cows[0][0])*(maxy-miny);

    miny=inf, maxy=1;
    vector<ll> pre(N), suf(N);
    for(int i=0; i<N; ++i){
        miny = min(miny, cows[i][1]);
        maxy = max(maxy, cows[i][1]);
        pre[i] = (cows[i][0]-cows[0][0])*(maxy-miny);
    }

    miny=inf, maxy=1;
    for(int i=N-1; ~i; --i){
        miny = min(miny, cows[i][1]);
        maxy = max(maxy, cows[i][1]);
        suf[i] = (cows[N-1][0]-cows[i][0])*(maxy-miny);
    }
    ll tot2=inf;
    for(int i=0; i<N-1; ++i){
        tot2 = min(tot2, pre[i]+suf[i+1]);
    }

    /* horizontal split */
    sort(cows, cows+N, cmp);
    fill(pre.begin(), pre.end(), 0);
    fill(suf.begin(), suf.end(), 0);

    ll minx=inf, maxx=1;
    for(int i=0; i<N; ++i){
        minx = min(minx, cows[i][0]);
        maxx = max(maxx, cows[i][0]);
        pre[i] = (cows[i][1]-cows[0][1])*(maxx-minx);
    }

    minx=inf, maxx=1;
    for(int i=N-1; ~i; --i){
        minx = min(minx, cows[i][0]);
        maxx = max(maxx, cows[i][0]);
        suf[i] = (cows[N-1][1]-cows[i][1])*(maxx-minx);
    }

    for(int i=0; i<N-1; ++i){
        tot2 = min(tot2, pre[i]+suf[i+1]);
    }
    cout << tot-tot2 << endl;
    return 0;
}
