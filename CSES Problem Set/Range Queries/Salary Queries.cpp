#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

template<class T> using oset=tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

const int maxn=2e5+1;
int n,q;
int a[maxn];
oset<pair<int,int> > se;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> q;
    for(int i=0;i<n;++i){
        cin >> a[i];
        se.insert({a[i],i});
    }
    while(q--){
        char ch;
        int x,y;
        cin >> ch >> x >> y;
        if(ch=='?'){
            cout<<se.order_of_key({y+1,0})-se.order_of_key({x,0})<<endl;
        }
        else{
            se.erase(se.find({a[x-1],x-1}));
            se.insert({y,x-1});
            a[x-1]=y;
        }
    }
    return 0;
}
