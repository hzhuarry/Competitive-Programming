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
const ll INF=1e16;
const int dx[4]= {-1,1,0,0}, dy[4]= {0,0,-1,1};
 
 
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    ll x;
    cin>>n>>x;
    vpii v(n+1);
    for(int i=1;i<=n;++i){
        cin>>v[i].f;
        v[i].s=i;
    }
    sort(v.begin()+1,v.end());
    for(int i=1;i<=n-2;++i){
        int start=i+1,finish=n;
        while(start<finish){
            ll sum=v[start].f+v[finish].f+v[i].f;
            if(sum==x){
                cout<<v[i].s<<" "<<v[start].s<<" "<<v[finish].s<<endl;
                exit(0);
            }
            else if(sum>x){
                finish--;
            }
            else{
                start++;
            }
        }
    }
    cout<<"IMPOSSIBLE"<<endl;
    return 0;
}
