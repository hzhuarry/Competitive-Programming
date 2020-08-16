#include <bits/stdc++.h>
using namespace std;


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n, k;
    cin >> n >> k;
    vector<int> a;
    vector<pair<int,int> > v;
    for(int i=1; i<=n; ++i){
        int r; 
        cin >> r;
        a.push_back(r);
        v.push_back({r,i});
    }
    sort(v.begin(), v.end());
    vector<int> ans(n, 0);
    for(int i=0; i<n; ++i){
        int j = lower_bound(v.begin(), v.end(), make_pair(v[i].first, -1)) - v.begin();
        ans[v[i].second-1] = j;
    }
    for(int i=0; i<k; ++i){
        int x, y;
        cin >> x >> y;
        --x, --y;
        if(a[x] > a[y]){
            --ans[x];
        }
        else if(a[x] < a[y]){
            --ans[y];
        }
    }
    for(int i=0; i<n; ++i){
        cout << (ans[i]>=0?ans[i]:0) << " ";
    }
    return 0;
}
