/*
ID: hzhu7271 
LANG: C++
TASK: sort3 
*/

#include <bits/stdc++.h>
using namespace std;

#define ar array

int N, a[1000], b[1000];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ifstream cin("sort3.in");
    ofstream cout("sort3.out");

    cin >> N;
    for(int i=0; i<N; ++i)
        cin >> a[i], b[i] = a[i];
    sort(b, b+N);

    int res = 0;
    for(int i=0; i<N; ++i) {
        if(a[i] == b[i])
            continue;
        for(int j=i+1; j<N; ++j) {
            if(a[j] == b[i] and a[i] == b[j]) {
                swap(a[i], a[j]);
                ++res;
                break;
            }
        }
    }
    for(int i=0; i<N; ++i) {
        if (a[i] == b[i]) 
            continue;
        for(int j=i+1; j<N; ++j) {
           if(a[j] == b[i] and a[j] != b[j]) {
                swap(a[i], a[j]);
                ++res;
                break;
            }
        }
    }
    cout << res << endl;
}
