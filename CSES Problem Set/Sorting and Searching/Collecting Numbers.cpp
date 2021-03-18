#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    vector<array<int, 2>> a(n);
    for(int i=0; i<n; ++i)
        cin >> a[i][0], a[i][1]=i;

    sort(a.begin(), a.end());
    int ans=1;
    for(int i=1; i<n; ++i) {
        if(a[i][1]<a[i-1][1])
            ++ans;
    }
    cout << ans;
    return 0;
}
