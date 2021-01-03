#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    long long sum = 0;
    vector<long long> a(7);
    for(int i=0; i<7; ++i) {
        cin >> a[i];
        sum += a[i];
    }
        
    sum /= 4;
    sort(a.begin(), a.end());
    cout << a[0] << " " << a[1] << " " << sum-(a[0]+a[1]) << '\n';
    return 0;
}


