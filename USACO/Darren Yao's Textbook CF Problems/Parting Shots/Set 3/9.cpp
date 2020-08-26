#include <bits/stdc++.h>
using namespace std;
 
const int MX = 2e5+50;
int n, res;
vector<int> adj[MX];
bool vis[MX];
 
void dfs(int i){
    vis[i] = 1;
    for(int j : adj[i]){
        if(vis[j])
            continue;
        dfs(j);
    }
}
 
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
 
    cin >> n;
    for(int i=0; i<n; ++i){
        string s;
        cin >> s;
        for(char ch : s){
            adj[i].push_back(n+ch-'a');
            adj[n+ch-'a'].push_back(i);
        }
    }
 
    for(int i=n; i<n+26; ++i){
        if(adj[i].empty() or vis[i])
            continue;
        dfs(i); ++res;
    }
    cout << res << endl;
    return 0;
}
