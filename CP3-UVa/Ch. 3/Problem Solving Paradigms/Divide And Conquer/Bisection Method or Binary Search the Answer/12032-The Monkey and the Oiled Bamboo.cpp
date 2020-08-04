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
typedef vector<char> vch;
typedef vector<str> vs;
typedef vector<ld> vld;
typedef vector<pii> vpii;
typedef vector<pll> vpll;
typedef vector<pld> vpld;

const int MOD = 1000000007;
const ll INF=1e18;
const int dx[4]= {-1,1,0,0}, dy[4]= {0,0,-1,1};

int n;
int a[100001];

bool ok(int k){
    for(int i=1;i<=n;++i){
        if(a[i]-a[i-1]>k){
            return 0;
        }
        if(a[i]-a[i-1]==k)k--;
    } 
    return 1;
}

int solve(){
    cin>>n;
    for(int i=1;i<=n;++i) cin>>a[i];
    int lo=1,hi=1e7;
    while(lo<hi){
        int mid=(lo+hi)/2;
        if(ok(mid)){
            hi=mid;
        }
        else{
            lo=mid+1;
        }
    }
   return lo; 
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin>>t;
    int c=1;
    while(t--){
        cout<<"Case "<<c++<<": "<<solve()<<endl;
    }
    return 0;
}
