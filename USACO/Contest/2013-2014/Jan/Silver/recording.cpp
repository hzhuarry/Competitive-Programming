#include <bits/stdc++.h>
using namespace std;

#define ar array

bool cmp(const ar<int,2>& a, const ar<int,2>& b){
    if(a[1]==b[1])
        return a[0] < b[0];
    return a[1] < b[1];
}

int N;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ifstream cin("recording.in");
    ofstream cout("recording.out");
    
    cin >> N;
    vector<ar<int,2> > v(N);
    for(int i=0; i<N; ++i)
        cin >> v[i][0] >> v[i][1];
    sort(v.begin(), v.end(), cmp);

    int res = 0;
    multiset<int> se;
    
    /* greedy sol */
    for(int i=0; i<N; ++i){
        bool used_prev=0;
        if(!se.empty()){
            auto it = se.upper_bound(v[i][0]);
            if(it!=se.begin()){
                --it;
                se.erase(it);
                se.insert(v[i][1]);
                ++res;
            }
        }
        if((int)se.size()<2 and !used_prev){
            se.insert(v[i][1]);
            ++res;
        }
    }
    cout << res << endl;
    return 0;
}
