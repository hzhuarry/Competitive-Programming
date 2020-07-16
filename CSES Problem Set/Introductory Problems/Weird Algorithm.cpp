#include <bits/stdc++.h>
using namespace std;
 
#define endl "\n"
#define pb(s) push_back(s)
#define mp(a,b) make_pair(a,b)
#define f first
#define se second
#define ALL(v) v.begin(), v.end()
#define ALLA(arr, sz) arr, arr + sz
#define SORT(v) sort(ALL(v))
#define REVERSE(v) reverse(ALL(v))
#define SORTA(arr, sz) sort(ALLA(arr, sz))
#define REVERSEA(arr, sz) reverse(ALLA(arr, sz))
#define PI 3.14159265358979323846264338327950L
 
 
typedef long long ll;
 
const ll MOD =1e9+7;
 
 
void solve(){
    ll n;
    cin>>n;
    cout<<n<<" ";
    while(n!=1){
        if(n==1){
            cout<<1;
            break;
        }
        if(n%2==0){
            n/=2;
        }
        else{
            n*=3;
            n++;
        }
        cout<<n<<" ";
    }
}
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    solve();
    return 0;
}
