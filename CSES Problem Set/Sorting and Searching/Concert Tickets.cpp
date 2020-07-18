#include <bits/stdc++.h>
 
using namespace std;
 
#define endl "\n"
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
    
    int n,m;
    cin>>n>>m;
    multiset<int> s;
    for(int i=0;i<n;++i){
        int h; cin>>h;
        s.insert(h);
    }
    for(int i=0;i<m;++i){
        int t; cin>>t;
        auto it=s.lb(t);
        if(it!=s.end()){
            if(*it<=t){
                cout<<*it<<endl;
                s.erase(it);
            }
            else{
                if(it!=s.begin()){
                    --it;
                    if(*it>t){
                        cout<<-1<<endl;
                    }
                    else{
                        cout<<*it<<endl;
                        s.erase(it);
                    }
                }
                else{
                    cout<<-1<<endl;
                }
            }
        }
        else{
            if(!s.empty()){
                cout<<*--s.end()<<endl;
                s.erase(--s.end());
            }
            else{
                cout<<-1<<endl;
            }
        }
    }
    return 0;
}
