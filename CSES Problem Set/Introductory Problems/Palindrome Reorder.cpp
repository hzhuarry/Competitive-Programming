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

    str s;
    cin>>s;
    int n=s.size();
    map<char,int> m;
    for(int i=0;i<n;++i){
        m[s[i]]++;
    }
    int numOdd=0;
    char oddC;
    int oddNum;
    for(auto it=m.begin();it!=m.end();++it){
        if(it->s%2==1){
            numOdd++;
            oddC=it->f;
            oddNum=it->s;
        }
    }
    deque<char> ans;
    if(n%2!=0){
        if(numOdd==1){
            for(int i=0;i<oddNum;++i){
                ans.pb(oddC);
            }
            for(auto it=m.begin();it!=m.end();++it){
                if(it->f==oddC)continue;
                char c=it->f;
                int x=it->s;
                for(int i=0;i<x/2;++i){
                    ans.pb(c);
                    ans.pf(c);
                }
            }
            for(int i=0;i<n;++i)
                cout<<ans[i];
        }
        else{
            cout<<"NO SOLUTION"<<endl;
        }
    }
    else{
        if(numOdd==0){
            for(auto it=m.begin();it!=m.end();++it){
                char c=it->f;
                int x=it->s;
                for(int i=0;i<x/2;++i){
                    ans.pb(c);
                    ans.pf(c);
                }
            }
            for(int i=0;i<n;++i){
                cout<<ans[i];
            }
        }
        else{
            cout<<"NO SOLUTION"<<endl;
        }
    }
    return 0;
}
