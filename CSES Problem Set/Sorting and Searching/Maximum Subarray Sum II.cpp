#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array
#define end \n

const int MX = 2e5;
int n, a, b;
ll presum[MX+1];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> a >> b;
    for(int i=1; i<=n; ++i){
        cin >> presum[i];
        presum[i] += presum[i-1];
    }

    set<ar<ll,2> > sum;
    ll ans = -1e18;

    for(int i=1; i<=n; ++i){
        if(i>=a){
            sum.insert({presum[i-a], i-a+1});
        }
        if(not sum.empty()){
            ans = max(ans, presum[i]-(*sum.begin())[0]);
        }
        if(i>=b){
            sum.erase({presum[i-b], i-b+1});
        }
    }
    cout << ans << endl;
    return 0;
}
