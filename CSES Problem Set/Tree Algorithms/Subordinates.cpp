#include <bits/stdc++.h>

using namespace std;

#define pb push_back

const int maxn=2e5;

int N;
vector<int> children[maxn];
int tree_sz[maxn];

void dfs(int node=0){
    tree_sz[node]=1;
    for(int child:children[node]){
        dfs(child);
        tree_sz[node]+=tree_sz[child];
    }
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin >> N;
    for(int i=1;i<N;++i){
        int parent; cin >> parent; --parent;
        children[parent].pb(i);
    }
    dfs();
    for(int i=0;i<N;++i){
        cout << tree_sz[i]-1 << " ";
    }
    return 0;
}
