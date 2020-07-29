/*
ID: hzhu7271 
LANG: C++
TASK: pprime 
*/

#include <bits/stdc++.h>

using namespace std;
#define pb push_back
#define all(x) x.begin(),x.end()
using ll = long long;

/* FILE IO */
void setIO(string filename = "") {
    ios_base::sync_with_stdio(0); cin.tie(0);
    if ((int)filename.size()) { /* USACO */
        freopen((filename+".in").c_str(), "r", stdin);
        freopen((filename+".out").c_str(), "w", stdout);
    }
}

int a,b;
vector<int> pali;

bool isPrime(int x){
    if(x<=1)
        return 0;
    if(x<=3)
        return 1;
    if(x%2==0 || x%3==0)
        return 0;
    for(int i=5;i*i<=x;i=i+6){
        if(x%i==0||x%(i+2)==0)
            return 0;
    }
    return 1;
}

int main(){
    setIO("pprime");
    cin >> a >> b;
    for(int i=1;i<=9;++i){
        pali.pb(i);
    }
    for(int i=1;i<=9;i+=2){
        pali.pb(10*i+i);
    }
    for(int i=1;i<=9;i+=2){
        for(int j=0;j<=9;++j){
            pali.pb(100*i+10*j+i);
        }
    }
    for(int i=1;i<=9;i+=2){
        for(int j=0;j<=9;++j){
            pali.pb(1000*i+100*j+10*j+i);
        }
    }
    for(int i=1;i<=9;i+=2){
        for(int j=0;j<=9;++j){
            for(int k=0;k<=9;++k){
                pali.pb(10000*i+1000*j+100*k+10*j+i);
            }
        }
    }
    for(int i=1;i<=9;i+=2){
        for(int j=0;j<=9;++j){
            for(int k=0;k<=9;++k){
                pali.pb(100000*i+10000*j+1000*k+100*k+10*j+i);
            }
        }
    }
    for(int i=1;i<=9;i+=2){
        for(int j=0;j<=9;++j){
            for(int k=0;k<=9;++k){
                for(int x=0;x<=9;++x){
                    pali.pb(1000000*i+100000*j+10000*k+1000*x+100*k+10*j+i);
                }
            }
        }
    }
    for(int i=1;i<=9;i+=2){
        for(int j=0;j<=9;++j){
            for(int k=0;k<=9;++k){
                for(int x=0;x<=9;++x){
                    pali.pb(10000000*i+1000000*j+100000*k+10000*x+1000*x+100*k+10*j+i);
                }
            }
        }
    }
    int ind1=lower_bound(all(pali),a)-pali.begin();
    int ind2=lower_bound(all(pali),b)-pali.begin();
    if(pali[ind2]>b){
        ind2--;
    }
    for(int i = ind1;i<=ind2;++i){
        if(isPrime(pali[i]))
            cout << pali[i] << endl;
    }
    return 0;
}
