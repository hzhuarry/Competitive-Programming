#include <bits/stdc++.h>
using namespace std;

const int MX = 200000;
int n, res;
int a[MX];
int dp_end[MX], dp_start[MX];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(int i=0; i<n; ++i)
        cin >> a[i];
    dp_end[0] = dp_start[n-1] = 1;
    for(int i=1; i<n; ++i){
        if(a[i] > a[i-1]){
            dp_end[i] = dp_end[i-1]+1;
        }
        else{
            dp_end[i]=1;
        }
        res = max(res, dp_end[i]);
    }
    for(int i=n-2; i>=0; --i){
        if(a[i] < a[i+1]){
            dp_start[i] = dp_start[i+1]+1;
        }
        else{
            dp_start[i] = 1;
        }
    }
    for(int i=1; i<n-1; ++i){
        if(a[i-1] < a[i+1])
            res = max(res, dp_end[i-1]+dp_start[i+1]);
    }
    cout << res << endl;
    return 0;
}
