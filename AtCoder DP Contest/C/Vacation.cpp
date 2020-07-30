#include <bits/stdc++.h>

using namespace std;
using ll = long long;

/* FILE IO */
void setIO(string filename = "") {
    ios_base::sync_with_stdio(0); cin.tie(0);
    if ((int)filename.size()) { /* USACO */
        freopen((filename+".in").c_str(), "r", stdin);
        freopen((filename+".out").c_str(), "w", stdout);
    }
}

int N;
array<int,3> activity[100000];
int dp[100000][3];

int main(){
    setIO();
    cin >> N;
    for(int i=0;i<N;++i){
        cin >> activity[i][0] >> activity[i][1] >> activity[i][2];
    }
    for(int i=0;i<3;++i){
        dp[0][i]=activity[0][i];
    }
    for(int i=1;i<N;++i){
        dp[i][0]=activity[i][0]+max(dp[i-1][1],dp[i-1][2]);
        dp[i][1]=activity[i][1]+max(dp[i-1][0],dp[i-1][2]);
        dp[i][2]=activity[i][2]+max(dp[i-1][0],dp[i-1][1]);
    }
    cout << max({dp[N-1][0], dp[N-1][1], dp[N-1][2]}) << endl;
    return 0;
}
