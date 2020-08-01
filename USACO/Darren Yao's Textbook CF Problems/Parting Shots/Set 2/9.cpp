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

int main() {
    setIO();
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> factors;
        for(int i=2;i*i<=n;++i){
            while(n%i==0){
                n/=i;
                factors.pb(i);
            }
        }
        if(n>1)
            factors.pb(n);
            
        int N=(int)factors.size();
        if(N>=3){
            int i=1;
            int last=factors[0],prod=1;
            int cnt=1;
            set<int> ans;
            ans.insert(factors[0]);
            while(cnt<3 && i<N){
                prod*=factors[i];
                if(cnt<2 && prod > last){
                    ++cnt;
                    ans.insert(prod);
                    last=prod;
                    prod=1;
                }
                ++i;
            }
            if(prod>1)
                ans.insert(prod);
                
            int sz=(int)ans.size();
            if(sz==3){
                cout << "YES" << endl;
                for(auto u:ans)
                    cout << u << " ";
                cout << endl;
            }
            else{
                cout << "NO" << endl;
            }
        }
        else{
            cout << "NO" << endl;
        }
    }
    return 0;
}

