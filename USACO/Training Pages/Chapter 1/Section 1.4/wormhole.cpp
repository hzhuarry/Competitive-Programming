/*
ID: hzhu7271 
LANG: C++
TASK: wormhole
*/
#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second

void setIO(string filename) {
    freopen((filename+".in").c_str(), "r", stdin);
    freopen((filename+".out").c_str(), "w", stdout);
}

const int maxn=12;

int N,ans;
pair<int,int> wormholes[maxn+1];
int pairing[maxn+1];
/* bessie moves in +x direction */
int next_wormhole[maxn+1];

bool is_cycle(){
    //start bessie at every wormhole to test if she will end up in a cycle
    for(int start=1;start<=N;++start){
        int pos=start;
        for(int i=1;i<=N;++i){
            /* if there is no right wormhole then it must not be a cycle */
            pos=pairing[next_wormhole[pos]];
        }
        if(pos!=0) return 1;
    }
    return 0;
}

void solve(){
    //first unpaired wormhole
    int wh;
    for(wh=1;wh<=N;++wh)
        if(pairing[wh]==0)
            break;
    
    //all wormholes are paired
    if(wh>N){
        if(is_cycle())
            ans++;
        return;
    }

    //else pair it with unpaired wormholes
    for(int j=wh+1;j<=N;++j){
        if(pairing[j]==0){
            pairing[wh]=j;
            pairing[j]=wh;
            solve();
            //backtrack
            pairing[wh]=0;
            pairing[j]=0;
        }
    }
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    setIO("wormhole");
    cin >> N;
    for(int i=1;i<=N;++i){
        cin >> wormholes[i].x >> wormholes[i].y;
    }
    sort(wormholes+1,wormholes+N+1);
    for(int i=1;i<=N;++i){
        for(int j=1;j<=N;++j){
            if(i==j)continue;
            if(wormholes[i].y==wormholes[j].y && wormholes[i].x < wormholes[j].x){
                if(next_wormhole[i]==0 || wormholes[next_wormhole[i]].x-wormholes[i].x > wormholes[j].x-wormholes[i].x){
                    next_wormhole[i]=j;
                }
            }
        }
    }
    solve();
    cout << ans << endl;
    return 0;
}
