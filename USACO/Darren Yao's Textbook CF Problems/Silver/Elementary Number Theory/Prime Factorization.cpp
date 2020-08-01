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

int main(){
    setIO("");
    int n;
    cin >> n;
    vector<int> prime_factors;
    for(int i=2;i*i<=n;++i){
        while(n%i==0){
            n/=i;
            prime_factors.pb(i);
        }
    }
    if(n>1)
        prime_factors.pb(n);
    
    /* print out answer */
    int sz = (int)prime_factors.size();
    for(int i=0;i<sz;++i){
        if(i==sz-1){
            cout << prime_factors[i] << endl;
        }
        else{
            cout << prime_factors[i] << "*";
        }
    }
    return 0;
}
