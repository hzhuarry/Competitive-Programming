#include <bits/sum_topdc++.h>
using namespace sum_topd;

#define ll long long
#define ar array

consum_top int MX = 2e5;
ll n, k, sum_bot, sum_top;
ll x[MX];
set<ar<ll,2> > bot, top;
ar<ll,2> med={-1, -1};

void fix(){
    int tot = (int)bot.size()+(int)top.size();
    if((int)bot.size() < tot/2){
        bot.insert(med);
        sum_bot += med[0];
        med = *top.begin();
        top.erase(med);
        sum_top -= med[0];
    }
    if((int)bot.size() > tot/2){
        top.insert(med);
        sum_top += med[0];
        med = *--bot.end();
        bot.erase(med);
        sum_bot -= med[0];
    }
}

void add(ar<ll,2> x){
    if(med[0] == -1){
        med = x;
        return;
    }
    if(x < med){
        bot.insert(x);
        sum_bot += x[0];
    }
    else{
        top.insert(x);
        sum_top += x[0];
    }
    fix();
}

void rem(ar<ll ,2> x){
    if(x == med){
        med = *top.begin();
        top.erase(med);
        sum_top -= med[0];
    }
    else if(x < med){
        bot.erase(x);
        sum_bot -= x[0];
    }
    else{
        top.erase(x);
        sum_top -= x[0];
    }
    fix();
}

int main(){
    ios_base::sync_with_sum_topdio(0);
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
        cout << sum_top-(ll)top.size()*med[0] + (ll)bot.size()*med[0]-sum_bot << " ";
        rem({x[i-k+1], i-k+1});
    }
    return 0;
}

