#include <bits/stdc++.h>
using namespace std;

int n, m;
int par[1000];

int find(int x) {
    return par[x] == x ? x : par[x] = find(par[x]);
}

void merge(int a, int b) {
    a = find(a);
    b = find(b);
    if(a != b) {
        par[b] = a;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    while(cin >> n >> m and n and m) {
        for(int i=0; i<n; ++i) {
            par[i] = i;
        }
        vector<array<int,3>> v;
        vector<int> ans;

        for(int i=0; i<m; ++i) {
            int a, b, w;
            cin >> a >> b >> w;
            v.push_back({w, a, b});
        }
        sort(v.begin(), v.end());

        for(array<int,3> x : v) {
            if(find(x[1]) != find(x[2])) {
                merge(x[1], x[2]);
            }
            else {
                ans.push_back(x[0]);
            }
        }

        if(ans.empty()) {
            cout << "forest" << endl;
        }
        else {
            for(int i=0; i<ans.size(); ++i) {
                if(i == ans.size()-1) {
                    cout << ans[i] << endl;
                }
                else {
                    cout << ans[i] << " ";
                }
            } 
        }
    }
    return 0;
}


