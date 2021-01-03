#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    vector<int> a(7);
    for(int i=0; i<7; ++i) {
        cin >> a[i];
    }
        
    sort(a.begin(), a.end());
    /* a, b, a+b+c-(a+b) */
    cout << a[0] << " " << a[1] << " " << a.back()-(a[0]+a[1]) << '\n';
    return 0;
}


