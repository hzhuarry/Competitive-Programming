#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    const string t = "RGB";
    int q;
    cin >> q;
    while(q--) {
        int n, k;
        string s;
        cin >> n >> k >> s;
        int ans = 1e9;
        for(int i=0; i<3; ++i) {
            vector<int> res(n, 0);
            int curr = 0;
            for(int j=0; j<n; ++j) {
                res[j] = (s[j]!=t[(j+i)%3]);
                curr += res[j];
                res[j] = curr;
                if(j==k-1){
                    ans = min(ans, curr);
                }
                if(j>=k) {
                    ans = min(ans, curr-res[j-k]);
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}

