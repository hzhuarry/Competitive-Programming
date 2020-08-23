#include <bits/stdc++.h>
using namespace std;

#define ar array

const int MX = 2e5;
int n, k;
int x[MX];
set<ar<int,2> > bot, top;
ar<int,2> med={-1, -1};

void fix(){
    int tot = (int)bot.size()+(int)top.size();
    if((int)bot.size() < tot/2){
        bot.insert(med);
        med = *top.begin();
        top.erase(med);
    }
    if((int)bot.size() > tot/2){
        top.insert(med);
        med = *--bot.end();
        bot.erase(med);
    }
}

void add(ar<int,2> x){
    if(med[0] == -1){
        med = x;
        return;
    }
    if(x < med){
        bot.insert(x);
    }
    else{
        top.insert(x);
    }
    fix();
}

void rem(ar<int,2> x){
    if(x == med){
        med = *top.begin();
        top.erase(med);
    }
    else if(x < med){
        bot.erase(x);
    }
    else{
        top.erase(x);
    }
    fix();
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;
    for(int i=0; i<n; ++i)
        cin >> x[i];

    if(k==1){
        for(int i=0; i<n; ++i){
            cout << x[i] << " ";
        }
        return 0;
    }

    for(int i=0; i<k-1; ++i){
        add({x[i], i});
    }
    for(int i=k-1; i<n; ++i){
        add({x[i], i});
        cout << med[0] << " ";
        rem({x[i-k+1], i-k+1});
    }
    return 0;
}
