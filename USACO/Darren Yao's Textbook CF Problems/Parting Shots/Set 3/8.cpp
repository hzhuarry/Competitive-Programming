#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--){
        const int MX = 2e5+1;
        int n; 
        string s;
        cin >> n >> s;
        map<array<int,2>, int> mp;
        int x = 0, y = 0;
        mp[{0, 0}] = 0;
        
        int res1 = -MX, res2 = MX;
        for(int i=0; i<n; ++i){
            if(s[i] == 'L')
                --x;
            else if(s[i] == 'R')
                ++x;
            else if(s[i] == 'U')
                ++y;
            else
                --y;
            if(mp.find({x, y}) != mp.end()){
                if(i-mp[{x, y}] < res2-res1){
                    res1 = mp[{x, y}]+1;
                    res2 = i+1;
                }
            }
            mp[{x, y}] = i+1;
        }
        if(res1 == -MX or res2 == MX)
            cout << -1 << endl;
        else 
            cout << res1 << " " << res2 << endl;
    }
    return 0;
}

