#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp> 
using namespace __gnu_pbds;
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
 
template <class T> using oset=tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    //find_by_order(k)
    int n,k;
    cin>>n>>k;
    vi v(n);
    for(int i=0;i<n;++i){
        cin>>v[i];
    }
    oset<pii> s;
    for(int i=0;i<n;)
    {
        if(i==0){
            for(int j=0;j<k;++j){
                s.insert({v[j],j});
            }
            i=k;
        }
        else{
            s.erase({v[i-k],i-k});
            s.insert({v[i],i});
            ++i;
        }
        cout<<s.find_by_order((k-1)/2)->f<<" ";
    }
    return 0;
}
