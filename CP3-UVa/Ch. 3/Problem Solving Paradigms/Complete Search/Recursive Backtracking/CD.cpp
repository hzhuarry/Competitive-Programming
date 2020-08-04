#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

#define endl "\n"
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define sz(x) (int)x.size()
#define all(x) begin(x), end(x)
#define alla(x,n) x,x+n
#define rall(x) (x).rbegin(), (x).rend()
#define Sort(x) sort(all(x))
#define Sorta(x,n) sort(alla(x,n))
#define rsz resize
#define ins insert
#define lb lower_bound
#define ub upper_bound
#define umap unordered_map
#define uset unordered_set
#define pqueue priority_queue
#define ar array

#define for_base(i, a, b, x) for (int i=((a)<(b))?(a):(a)-1; ((a)<(b))?i<(b):i>=(b); ((a)<(b))?i+=(x):i-=(x))
#define FOR1(a) for_base(i, 0, a, 1)
#define FOR2(i, a) for_base(i, 0, a, 1)
#define FOR3(i, a, b) for_base(i, a, b, 1)
#define FOR4(i, a, b, x) for_base(i, a, b, x)
#define FIFTH(a, b, c, d, e, ...) e
#define FOR(...) FIFTH(__VA_ARGS__, FOR4, FOR3, FOR2, FOR1)(__VA_ARGS__)
#define trav(a,x) for (auto& a: x)
#define fitfor(i, x) for (auto i=(x).begin(); i!=(x).end(); ++i)
#define ritfor(i, x) for (auto i=(x).rbegin(); i!=(x).rend(); ++i)

typedef long long ll;
typedef long double ld;
typedef double db;
typedef string str;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<db,db> pdd;
typedef pair<ld,ld> pld;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<db> vd;
typedef vector<str> vs;
typedef vector<ld> vld;
typedef vector<pii> vpii;
typedef vector<pll> vpll;
typedef vector<pld> vpld;
typedef vector<pdd> vpdd;
template<class T> using min_heap=pqueue<T, vector<T>, greater<T>>;
template<class T> using oset=tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

const int MOD = 1000000007;
const ll INF=1e18;
const int dx[4]= {-1,1,0,0}, dy[4]= {0,0,-1,1};


int N,d;
vi ansTrack;
int ans,ansSum;

void solve(int N,vi v, int currIndex, int sum, vi& tracks){
    if(sum>N)return;
    if(N-sum<ans && currIndex==sz(v)){
       ans=N-sum;
        ansSum=sum;
       ansTrack.clear();
       FOR(sz(tracks))
           ansTrack.pb(tracks[i]);
       return;
    }
    //in-case the second if doesn't pass so we check if we have reached the end of the vector
    if(currIndex==sz(v)) return;

    //standard recursive backtracking
    sum+=v[currIndex];
    tracks.pb(v[currIndex]);
    solve(N,v,currIndex+1,sum,tracks);
    sum-=v[currIndex];
    tracks.pop_back();
    solve(N,v,currIndex+1,sum,tracks);
}

int main() {
    while(scanf("%d %d",&N,&d)!=EOF){
        vi v(d);
        FOR(d)
            scanf("%d",&v[i]);
        vi tracks; int sum=0; int index=0;
        ans=1e9; ansSum=0;
        solve(N,v,index,sum,tracks);
        trav(t,ansTrack){
            printf("%d ",t);
        }
        printf("sum:%d\n",ansSum);
    }    
    return 0;
}
