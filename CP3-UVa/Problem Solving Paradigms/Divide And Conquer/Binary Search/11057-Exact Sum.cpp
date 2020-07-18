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
    int N;
    while(scanf("%d",&N)!=EOF){
        vi books(N);
        for(int i=0;i<N;++i){
            scanf("%d",&books[i]);
        }
        SORT(books);
        int M,p1=0,p2=1000001;
        cin>>M;
        for(int i=0;i<N;++i){
            int left=M-books[i];
            auto it=lb(ALL(books),left);
            if(it!=books.end()&&*it==left){
                if(abs(left-books[i])<abs(p2-p1)){
                    p1=left;
                    p2=books[i];
                }
            }
        }
        if(p1>p2) swap(p1,p2);
        printf("Peter should buy books whose prices are %d and %d.\n\n",p1,p2);
    }
    return 0;
}
