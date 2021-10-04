#include <bits/stdc++.h>
using namespace std;

/* p is prev index */
int n, x[(int)2e5 + 1], p[(int)2e5 + 1];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    while(cin >> n) {
        memset(p, -1, sizeof(p));
        for(int i=0; i<n; ++i)
            cin >> x[i];

        /* patient sort to find lis */
        vector<array<int, 2>> a;
        for(int i=0; i<n; ++i) {
            auto it = lower_bound(a.begin(), a.end(), array<int, 2>{x[i], -1});
            int idx = it - a.begin();
            if(it == a.end() or a.empty()) {
                if(a.size())
                    p[i] = a[idx - 1][1];
                a.push_back({x[i], i});
            }
            else if(it == a.begin()) {
                a[idx] = {x[i], i};
            }
            else {
                a[idx] = {x[i], i};
                p[i] = a[idx - 1][1];
            }
        }
        cout << a.size() << endl;

        vector<int> ans;
        int start = a.back()[1];
        
        /* backtrack */
        while(start != -1) {
            ans.push_back(start);
            start = p[start];
        }
        reverse(ans.begin(), ans.end());
        for(int idx : ans)
            cout << idx << " ";
        cout << '\n';
    }
}

