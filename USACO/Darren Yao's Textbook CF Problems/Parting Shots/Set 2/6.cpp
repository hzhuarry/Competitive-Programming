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
    int q;
    cin >> q;
    while(q--){
        int n,m;
        cin >> n >> m;
        vector<vector<char>> grid(n,vector<char>(m));
        for(int i=0;i<n;++i)
            for(int j=0;j<m;++j)
                cin >> grid[i][j];
        vector<int> cntn(n), cntm(m);
        for(int i=0;i<n;++i){
            for(int j=0;j<m;++j){
                cntn[i]+=(grid[i][j]=='.');
                cntm[j]+=(grid[i][j]=='.');
            }
        }
        int res=n*m;
        for(int i=0;i<n;++i){
            for(int j=0;j<m;++j){
                res=min(res,cntn[i]+cntm[j]-(grid[i][j]=='.'));
            }
        }
        cout << res << endl;
    }
    return 0;
}
