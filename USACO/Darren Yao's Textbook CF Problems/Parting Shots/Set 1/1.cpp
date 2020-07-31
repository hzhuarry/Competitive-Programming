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
    vector<int> v(n), ans(n), used(n);
    for(int i=0;i<n;++i){
        cin >> v[i];
        v[i]--;
        ans[i]= -1;
    }
    int mmax=-1;
    for(int i=0;i<n;++i){
        if(v[i]>mmax){
            mmax=v[i];
            ans[i]=v[i];
            used[v[i]]=1;
        }
        else if(v[i]<mmax){
            cout << -1 << endl;
            return;
        }
    }
    vector<int> next;
    for(int i=0;i<n;++i){
        if(!used[i]){
            next.pb(i);
        }
    }
    sort(next.begin(),next.end(),greater<int>());
    for(int i=0;i<n;++i){
        if(ans[i]==-1){
            ans[i]=next.back();
            next.pop_back();
        }
    }
    mmax=-1;
    for(int i=0;i<n;++i){
        mmax = max(mmax,ans[i]);
        if(mmax!=v[i]){
            cout << -1 << endl;
            return;
        }
    }
    for(int i=0;i<n;++i)
        cout << ans[i]+1 << " ";
    cout << endl;
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
