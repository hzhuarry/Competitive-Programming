#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define pb push_back
#define ar array

typedef long long ll;
typedef string str;

void setIO(string filename = "") {
    ios_base::sync_with_stdio(0); cin.tie(0);
    if ((int)filename.size()) {
        freopen((filename+".in").c_str(), "r", stdin);
        freopen((filename+".out").c_str(), "w", stdout);
    }
}

ll k,n,a,b;

bool ok(ll x){
    ll charge_left = k - x*a;
    ll rest = (n-x)*b;
    return charge_left-rest > 0;
}

int main() {
    setIO();
    int q; cin >> q;
    while(q--){
        cin >> k >> n >> a >> b;
        ll lo=-1,hi=n;
        while(lo<hi){
            int mid=(lo+hi+1)/2;
            if(ok(mid))
                lo=mid;
            else
                hi=mid-1;
        }
        cout << lo << endl;
    }
    return 0;
}
