/*
ID: hzhu7271
LANG: C++
TASK: runround
*/
#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll M;

bool ok(ll x) {
    string ss = to_string(x);
    int n=ss.size();

    /* must be distinct */
    set<int> se;
    for(int i=0; i<n; ++i)
        se.insert(ss[i]-'0');
    if(se.size()!=n or se.find(0)!=se.end())
        return 0;

    /* must cycle back */
    int i=0;
    char prev=ss[0], curr;
    vector<bool> vis(n, 0);
    while(!vis[i]) {
        vis[i]=1;
        i = (i+(ss[i]-'0'))%n;
        curr=ss[i];
        if(prev==curr)
            return 0;
        prev=curr;
    }
    return (count(vis.begin(), vis.end(), 1)==n) and (i==0); 
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ifstream cin("runround.in");
    ofstream cout("runround.out");

    cin >> M;
    /* brute force because 9*9! < 4e6*/
    while(1) {
        ++M;
        if(ok(M)) {
            cout << M << "\n";
            return 0;
        }
    }
    return 0;
}
