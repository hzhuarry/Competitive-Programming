#include <bits/stdc++.h>
 
using namespace std;
 
#define endl "\n"
#define sz(x) (int)x.size()
#define pf push_front
#define pb(s) push_back(s)
#define mp(a,b) make_pair(a,b)
#define f first
#define s second
#define ALL(v) v.begin(), v.end()
#define ALLA(arr, sz) arr, arr + sz
#define SORT(v) sort(ALL(v))
#define REVERSE(v) reverse(ALL(v))
#define SORTA(arr, sz) sort(ALLA(arr, sz))
#define REVERSEA(arr, sz) reverse(ALLA(arr, sz))
#define PI 3.14159265358979323846264338327950L
#define lb lower_bound
#define ub upper_bound
 
typedef long long ll;
typedef long double ld;
typedef string str;
 
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<ld,ld> pld;
 
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<char> vc;
typedef vector<str> vs;
typedef vector<ld> vd;
 
typedef vector<pii> vpii;
typedef vector<pll> vpll;
typedef vector<pld> vpd;
 
const int MOD = 1000000007;
const ll INF=1e18;
const int dx[4]= {-1,1,0,0}, dy[4]= {0,0,-1,1};
 
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin>>n;
    ll sum1=0;
    vi v(n);
    for(int i=0;i<n;++i){
        cin>>v[i];
        sum1+=v[i];
    }
    ll ans=INF;
    for(int i=0;i<(1<<n);++i){
        ll sum2=0;
        for(int j=0;j<n;++j){
            if((i&(1<<j))>0){
                sum2+=v[j];
            }
        }
        ans=min(ans,abs((sum1-sum2)-sum2));
    }
    cout<<ans<<endl;
    return 0;
}
