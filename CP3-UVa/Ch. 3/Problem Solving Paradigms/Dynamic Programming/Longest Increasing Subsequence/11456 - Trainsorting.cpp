#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
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

int main() {
    setIO();
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> train(n);
        for(int i=0;i<n;++i)
            cin >> train[i];
        vector<int> lis(n,1);
        vector<int> lds(n,1);
        for(int i=n-2;i>=0;--i){
            for(int j=i+1;j<n;++j){
                if(train[i] < train[j]){
                    lis[i]=max(lis[i],lis[j]+1);
                }
            }
        }
        for(int i=n-2;i>=0;--i){
            for(int j=i+1;j<n;++j){
                if(train[i] > train[j]){
                    lds[i]=max(lds[i],lds[j]+1);
                }
            }
        }
        int res=0;
        for(int i=0;i<n;++i)
            res=max(res,lds[i]+lis[i]-1);
        cout << res << endl;
    }
    return 0;
}
