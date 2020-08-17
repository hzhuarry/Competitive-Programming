#include <bits/stdc++.h>
using namespace std;

const int MX = 1e6+1;
int N, M;
int Bspeed[MX], Espeed[MX];
/* 0 = B lead, 1 = E lead */
int currLead = -1, res;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    ifstream cin("cowrace.in");
    ofstream cout("cowrace.out");
    
    cin >> N >> M;
    int T = 0;
    for(int i=0; i<N; ++i){
        int speed, time;
        cin >> speed >> time;
        for(int j=0; j<time; ++j){
            Bspeed[T] = speed; 
            ++T;
        }
    }
    
    T = 0;
    for(int i=0; i<M; ++i){
        int speed, time;
        cin >> speed >> time;
        for(int j=0; j<time; ++j){
            Espeed[T] = speed;
            ++T;
        }
    }

    int b_pos = 0, e_pos = 0;
    for(int i=0; i<MX; ++i){
        b_pos += Bspeed[i];
        e_pos += Espeed[i];
        if(b_pos > e_pos){
            if(currLead == 1){
                ++res;
            }
            currLead = 0;
        }
        else if(e_pos > b_pos){
            if(currLead == 0){
                ++res;
            }
            currLead = 1;
        }
    }
    cout << res << endl;
    return 0;
}
