#include <bits/stdc++.h>
using namespace std;

#define ar array

int N, B, f[250];
ar<int, 2> d[250];
bool dp[251][251];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ifstream cin("snowboots.in");
    ofstream cout("snowboots.out");

    cin >> N >> B;
    for(int i=0; i<N; ++i) {
        cin >> f[i];
    }
    for(int i=0; i<B; ++i) {
        cin >> d[i][0] >> d[i][1];
    }

    for(int i=1; i<=B; ++i)
        dp[1][i]=1;
    
    /* push dp */
    for(int i=1; i<N; ++i) {
        for(int j=1; j<=B; ++j) {
            if(!dp[i][j])
                continue;
            for(int k=j; k<=B; ++k) {
                if(f[i-1] <= d[k-1][0]) {
                    for(int l=i+1; l<=min(N, i+d[k-1][1]); ++l) {
                        /* if the ending pile is too big then we do not go there with boot k */
                        if(f[l-1] > d[k-1][0])
                            continue;
                        dp[l][k]=1;
                    }
                }
            }
        }
    }

    for(int i=1; i<=B; ++i) {
        if(dp[N][i])
            return cout << i-1, 0;
    }
    return 0;
}


