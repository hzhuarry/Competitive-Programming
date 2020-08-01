#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define pb push_back
#define ar array

typedef long long ll;
typedef string str;

void setIO(string filename = "") {
    ios_base::sync_with_stdio(0); cin.tie(0);
    if ((int)filename.size()) {
        freopen((filename+".in").c_str(), "r", stdin);
        freopen((filename+".out").c_str(), "w", stdout);
    }
}

int n,x;
int h[1000],s[1000];
/* pages/price */
int dp[1001][100001];

int main() {
    setIO();
    cin >> n >> x;
    for(int i=0;i<n;++i){
        cin >> h[i];
    }
    for(int i=0;i<n;++i){
        cin >> s[i];
    }
    for(int i=1;i<=n;++i){
        int price=h[i-1], pages=s[i-1];
        for(int j=1;j<=x;++j){
            dp[i][j] = dp[i-1][j];
            if(j>=price && dp[i-1][j-price]+pages > dp[i][j]){
                dp[i][j] = dp[i-1][j-price] + pages;
            }
        }
    } 
    cout << dp[n][x] << endl;
    return 0;
}
