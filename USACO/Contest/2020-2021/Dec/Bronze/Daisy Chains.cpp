#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;
    vector<int> p(N);
    for(int i=0; i<N; ++i)
        cin >> p[i];

    int ans = 0;
    for(int i=0; i<N; ++i) {
        int sum = 0;
        for(int j=i; j<N; ++j) {
            sum+=p[j];
            if((sum % (j-i+1)) != 0)
                continue;
            int avg = sum / (j-i+1);
            for(int k=i; k<=j; ++k) {
                if(p[k] == avg) {
                    ++ans;
                    break;
                }
            }
        }
    }
    cout << ans;
    return 0;
}


