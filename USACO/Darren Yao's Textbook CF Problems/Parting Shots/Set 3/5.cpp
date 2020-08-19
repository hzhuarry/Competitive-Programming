#include <bits/stdc++.h>
using namespace std;

int n, b, a;
int s[200000];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> b >> a;
    for(int i=0; i<n; ++i)
        cin >> s[i];
    int i=0;
    int battery=b, accum=a;
    for(; i<n; ++i){
        if(battery==0 and accum==0)
            break;
        if(s[i]){
            if(accum==a){
                --accum;
            }
            else{
                if(battery){
                --battery;
                ++accum;
                }
                else{
                    --accum;
                }
            }
        }
        else{
            if(accum)
                --accum;
            else
                --battery;
        }
    }
    cout << i << endl;
    return 0;
}
