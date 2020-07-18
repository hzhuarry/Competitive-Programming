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

 
int n,a,b;
vector<tuple<int,bool,int>> events;
unordered_set<int> available_rooms;
int allocated_rooms[200001];
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    cin>>n;
    for(int i=0;i<n;++i){
        cin>>a>>b;
        events.push_back({a,false,i});
        events.push_back({b,true,i});
    }
    SORT(events);
    int smallest_unused_room=0;
    for(auto event:events){
        bool is_checkout=get<1>(event);
        int i=get<2>(event);
 
        if(is_checkout){
            available_rooms.insert(allocated_rooms[i]);
        }
        else{
            if(available_rooms.empty()){
                available_rooms.insert(smallest_unused_room++);
            }
            auto popped_room = available_rooms.begin();
            int room_number=*popped_room;
            available_rooms.erase(popped_room);
            allocated_rooms[i]=room_number;
        }
    }
    cout<<smallest_unused_room<<endl;
    for(int i=0;i<n;++i)
        cout<<allocated_rooms[i]+1<<" ";
    return 0;
}
