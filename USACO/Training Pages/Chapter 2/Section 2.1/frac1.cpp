/*
ID: hzhu7271 
LANG: C++
TASK: frac1
*/
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

int N;
set<pair<double,string> > se;
set<double> seen;

int main() {
    setIO("frac1");
    cin >> N;
    for(double dem=1;dem<=N;++dem){
        for(double num=0;num<=dem;++num){
            string x = "";
            x.append(to_string((int)num)+"/"+to_string((int)dem));
            if(seen.find(num/dem)==seen.end()){
                seen.insert(num/dem);
                se.insert({num/dem,x});
            }
        }
    }
    for(auto u:se)
        cout << u.second << endl;
    return 0;
}
