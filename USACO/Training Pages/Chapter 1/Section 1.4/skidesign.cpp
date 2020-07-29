/*
ID: hzhu7271 
LANG: C++
TASK: skidesign
*/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

/* FILE IO */
void setIO(string filename = "") {
    ios_base::sync_with_stdio(0); cin.tie(0);
    if ((int)filename.size()) { /* USACO */
        freopen((filename+".in").c_str(), "r", stdin);
        freopen((filename+".out").c_str(), "w", stdout);
    }
}

const int maxn=1000;
int N;
int hill[maxn];

int main(){
    setIO("skidesign");
    cin >> N;
    for(int i=0;i<N;++i){
        cin >> hill[i];
    }
    sort(hill,hill+N);
    
    int min_cost=INT_MAX;
    /* try every interval (i,i+17) */
    /* 83+17=100 */
    for(int i=0;i<=83;++i){
        int cost=0;
        int diff;
        for(int j=0;j<N;++j){
            if(i>hill[j]){
                diff=i-hill[j];
            }
            else if(i<hill[j]-17){
                diff=hill[j]-17-i;
            }
            else{
                diff=0;
            }
            cost+=diff*diff;
        }
        min_cost = min(min_cost,cost);
    }
    cout << min_cost << endl;
    return 0;
}
