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
    int n,k;
    cin >> n >> k;
    vector<ll> v(n);
    int sum=0;
    for(int i=0;i<n;++i){
        cin >> v[i];
        sum+=v[i];
    }
    if(sum%2==0){
        if(k%2!=0){
            cout << "NO" << endl;
            return;
        }
        else{
            ll sum2=0;
            vector<int> ans;
            for(int i=0,cnt_k=1;cnt_k<k && i<n;++i){
                sum2+=v[i];
                if(sum2%2==1){
                    ++cnt_k;
                    ans.pb(i+1);
                    sum2=0;
                }
            }
            ans.pb(n);
            if((int)ans.size()==k){
                cout << "YES" << endl;
                for(int i:ans)
                    cout << i << " ";
                cout << endl;
            }
            else{
                cout << "NO" << endl;
            }
        }
    }
    else{
        if(k%2!=1){
            cout << "NO" << endl;
            return;
        }
        else{
            ll sum2=0;
            vector<int> ans;
            for(int i=0,cnt_k=1;cnt_k<k && i<n;++i){
                sum2+=v[i];
                if(sum2%2==1){
                    ++cnt_k;
                    ans.pb(i+1);
                    sum2=0;
                }
            }
            ans.pb(n);
            if((int)ans.size()==k){
                cout << "YES" << endl;
                for(int i:ans)
                    cout << i << " ";
                cout << endl;
            }
            else{
                cout << "NO" << endl;
            }
        }
    }
}

int main(){
    setIO();
    int q;
    cin >> q;
    while(q--){
        solve();
    }
    return 0;
}
