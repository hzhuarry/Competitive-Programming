#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<ll> a(n);
        for(int i=0; i<n; ++i)
            cin >> a[i];

        ll ans = 0;
        for(int i=1; i<n; ++i){
            ll d = a[i-1]-a[i], c = 31;
            if(d<=0)
                continue;
            while(d < 1LL<<c){
                --c;
            }
            a[i] = a[i-1];
            ans = max(ans, c+1);
        }
        cout << ans << endl;
    }
    return 0;
}

