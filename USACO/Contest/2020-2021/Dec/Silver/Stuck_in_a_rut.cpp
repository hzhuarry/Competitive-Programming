#include <bits/stdc++.h>
using namespace std;

#define ar array

int N, ans[1000];
vector<ar<int, 3>> e, n;

/* sort by y value */
bool c1(const ar<int, 3>& a, const ar<int, 3>& b) {
    return a[1] < b[1];
}

/* sort by x value */
bool c2(const ar<int, 3>& a, const ar<int, 3>& b) {
    return a[0] < b[0];
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for(int i=0; i<N; ++i) {
        char c;
        int x, y;
        cin >> c >> x >> y;
        if(c=='E') {
            e.push_back({x, y, i});
        }
        else {
            n.push_back({x, y, i});
        }
    }

    sort(e.begin(), e.end(), c1);
    sort(n.begin(), n.end(), c2);
    vector<bool> stopped(N, 0);

    for(ar<int, 3> u : e) {
        int x=u[0], y=u[1], ind=u[2];
        for(ar<int, 3> other : n) {
            int x2=other[0], y2=other[1], ind2=other[2];
            /* a cow going north has a lower x value or higher y value than the current east going cow will never stop the current cow */
            if(x2<x or y2>y)
                continue;
            /* if the cow going north has been stopped by an earlier y valued cow, then it can't reach the current cow so it keeps on going east */
            if(stopped[ind2])
                continue;
            int time=x2-x;
            if(y2+time>y) {
                stopped[ind]=1;
                ans[ind2]+=ans[ind]+1;
                goto start;
            }
            else if(y2+time<y) {
                stopped[ind2]=1;
                ans[ind]+=ans[ind2]+1;
            }
        }
        start:
            ;
    }
    for(int i=0; i<N; ++i)
        cout << ans[i] << '\n';
    return 0;
}
