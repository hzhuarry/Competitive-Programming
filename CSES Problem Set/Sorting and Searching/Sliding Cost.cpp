#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define ar array
 
const int MX = 2e5;
ll n, k, sb, st;
ll x[MX];
set<ar<ll,2> > bot, top;
ar<ll,2> med={-1, -1};
 
void fix(){
    int tot = (int)bot.size()+(int)top.size();
    if((int)bot.size() < tot/2){
        bot.insert(med);
        sb += med[0];
        med = *top.begin();
        top.erase(med);
        st -= med[0];
    }
    if((int)bot.size() > tot/2){
        top.insert(med);
        st += med[0];
        med = *--bot.end();
        bot.erase(med);
        sb -= med[0];
    }
}
 
void add(ar<ll,2> x){
    if(med[0] == -1){
        med = x;
        return;
    }
    if(x < med){
        bot.insert(x);
        sb += x[0];
    }
    else{
        top.insert(x);
        st += x[0];
    }
    fix();
}
 
void rem(ar<ll ,2> x){
    if(x == med){
        med = *top.begin();
        top.erase(med);
        st -= med[0];
    }
    else if(x < med){
        bot.erase(x);
        sb -= x[0];
    }
    else{
        top.erase(x);
        st -= x[0];
    }
    fix();
}
 
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
 
    cin >> n >> k;
    for(ll i=0; i<n; ++i)
        cin >> x[i];
 
    if(k==1){
        for(ll i=0; i<n; ++i){
            cout << 0 << " ";
        }
        return 0;
    }
 
    for(ll i=0; i<k-1; ++i){
        add({x[i], i});
    }
    for(ll i=k-1; i<n; ++i){
        add({x[i], i});
        cout << st-(ll)top.size()*med[0] + (ll)bot.size()*med[0]-sb << " ";
        rem({x[i-k+1], i-k+1});
    }
    return 0;
}
