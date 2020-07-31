#include <bits/stdc++.h>

using namespace std;
#define pb push_back
using ll = long long;

/* FILE IO */
void setIO(string filename = "") {
    ios_base::sync_with_stdio(0); cin.tie(0);
    if ((int)filename.size()) { /* USACO */
        freopen((filename+".in").c_str(), "r", stdin);
        freopen((filename+".out").c_str(), "w", stdout);
    }
}

void solve(){
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i=0;i<n;++i){
        cin >> v[i];
    }
    for(int i=0;i<n-2;++i){
        for(int j=i+2;j<n;++j){
            if(v[i]==v[j]){
                cout << "YES" << endl;
                return;
            }
        }
    }
    cout << "NO" << endl;
}

int main(){
    setIO();
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
