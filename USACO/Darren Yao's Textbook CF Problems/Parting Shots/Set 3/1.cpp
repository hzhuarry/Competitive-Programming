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

int n,m;

int main() {
    setIO();
    cin >> n >> m;
    vector<pair<int,int> > pairs;
    for(int i=0;i<m;++i){
        int a,b;
        cin >> a >> b;
        --a,--b;
        pairs.push_back({a,b});
    }
    vector<int> possible = {pairs[0].first, pairs[0].second};
    for(int i : possible){
        vector<int> a(n,0);
        int cnt = 0;
        for(auto p : pairs){
            if(p.first == i or p.second == i)
                continue;
            a[p.first]++;
            a[p.second]++;
            ++cnt;
        }
        if(*max_element(a.begin(),a.end()) == cnt){
            cout << "YES" << endl;
            return 0;
        }
    }
    cout << "NO" << endl;
    return 0;
}
