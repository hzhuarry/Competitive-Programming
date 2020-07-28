#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void setIO(string filename = "") {
    ios_base::sync_with_stdio(0); cin.tie(0);
    if ((int)filename.size()) { /* USACO */
        freopen((filename+".in").c_str(), "r", stdin);
        freopen((filename+".out").c_str(), "w", stdout);
    }
}

int N;
map<ll,ll> m;
ll no_tele_dist, max_dist_change;

int main(){
    setIO("teleport");
    cin >> N;
    for(int i=0;i<N;++i){
        ll a,b;
        cin >> a >> b;
        if((a<0 && b<0) || (a>0&&b>0)){
            ll change = abs(b) - 2*abs(a);
            if(change > 0){
                m[b]+=2;
                m[b-change]-=1;
                m[b+change]-=1;
            }
        }
        else{
            m[b]+=2;
            m[2*b]-=1;
            m[0]-=1;
        }
        no_tele_dist+=abs(a-b);
    }
    ll curr_change=0, curr_slope=0;
    ll prev_y = m.begin()->first;
    for(auto it=m.begin();it!=m.end();++it){
        ll y = it->first, change = it->second;
        curr_change += curr_slope * (y-prev_y);
        /* most negative displacement */
        max_dist_change = min(max_dist_change,curr_change);
        prev_y = y;
        curr_slope+=change;
    }
    cout << no_tele_dist + max_dist_change << endl;
    return 0;
}
