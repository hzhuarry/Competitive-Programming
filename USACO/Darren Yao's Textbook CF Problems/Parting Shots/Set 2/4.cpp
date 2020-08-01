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
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i=0;i<n;++i){
        cin >> v[i];
    }
    sort(v.begin(),v.end());
    int start=0,ans=0;
    for(int end=0;end<n;++end){
        while(v[end]-v[start] > 5){
            start++;
        }
        ans=max(ans,end-start+1);
    }
    cout << ans << endl;
    return 0;
}

