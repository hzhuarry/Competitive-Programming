#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int q;
    cin >> q;
start:
    while(q--){
        int n, m;
        cin >> n >> m;
        vector<array<int,3>> v(n);
        for(int i=0; i<n; ++i)
            cin >> v[i][0] >> v[i][1] >> v[i][2];
        
        int lo = m, hi = m;
        int T = 0;
        for(int i=0; i<n; ++i){
            int time_diff = v[i][0] - T;
            T = v[i][0];
            /* check for intersection with ranges */
            if(lo-time_diff <= v[i][2] and hi+time_diff >= v[i][1]){
                lo = max(lo-time_diff, v[i][1]);
                hi = min(hi+time_diff, v[i][2]);
                continue;
            }
            cout << "no" << endl;
            goto start;
        }
        cout << "yes" << endl;
    }
    return 0;
}

