#/*
ID: hzhu7271 
LANG: C++
TASK: holstein 
*/

#include <bits/stdc++.h>
using namespace std;

int V, G, ans = 15;
int vitamins[25], type[15][25];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ifstream cin("holstein.in");
    ofstream cout("holstein.out");

    cin >> V;
    for(int i=0; i<V; ++i) {
        cin >> vitamins[i];
    }
    cin >> G;
    for(int i=0; i<G; ++i) {
        for(int j=0; j<V; ++j) {
            cin >> type[i][j];
        }
    }

    vector<int> ans_v;
    for(int i=0; i<(1<<G); ++i) {
        vector<int> tmp(V, 0), ind;
        int cnt = 0;
        for(int j=0; j<G; ++j) {
            if(i&(1<<j)) {
                ++cnt;
                ind.push_back(j+1);
                for(int k=0; k<V; ++k) {
                    tmp[k] += type[j][k];
                }
            }
        }

        bool f = 1;
        for(int j=0; j<V; ++j) {
            if(tmp[j] < vitamins[j]) {
                f = 0;
                break;
            }
        }
        if(f and cnt < ans) {
            ans = cnt;
            ans_v = ind;
        }
    }
    cout << ans << " ";
    for(int i=0; i<ans_v.size(); ++i) {
        if(i==ans_v.size()-1) {
            cout << ans_v[i] << endl;
        }
        else {
            cout << ans_v[i] << " ";
        }
    }
    return 0;
}


