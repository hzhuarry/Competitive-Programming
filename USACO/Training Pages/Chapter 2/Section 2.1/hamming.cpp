#/*
ID: hzhu7271 
LANG: C++
TASK: hamming 
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ifstream cin("hamming.in");
    ofstream cout("hamming.out");

    int N, B, D;
    cin >> N >> B >> D;

    set<int> s;
    /* brute force */
    for(int i=0; i<=(1<<B); ++i) {
        s.insert(i);
        bool done = 0;
        for(int j=0; j<=(1<<B); ++j) {
            if(i == j)
                continue;
            bool ok = 1;
            for(int x : s) {
                if(__builtin_popcount(x^j) < D) {
                    ok = 0;
                    break;
                }
            }
            if(ok)
                s.insert(j);
            if((int)s.size() == N) {
                done = 1;
                break;
            }
        }
        if(done)
            break;
        s.clear();
    }
    int cnt = 1;
    for(int i : s) {
        if(cnt == N or cnt%10 == 0)
            cout << i << endl;
        else
            cout << i << " ";
        ++cnt;
    }
    return 0;
}


