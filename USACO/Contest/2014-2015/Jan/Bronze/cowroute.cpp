#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define pb push_back
#define ar array

typedef long long ll;
typedef string str;

void setIO(string filename = "") {
    ios_base::sync_with_stdio(0); cin.tie(0);
    if ((int)filename.size()) {
        freopen((filename+".in").c_str(), "r", stdin);
        freopen((filename+".out").c_str(), "w", stdout);
    }
}

int A,B,N;
int cost[501];
vector<int> routes[501];

int main() {
    setIO("cowroute");
    cin >> A >> B >> N;
    for(int i=0;i<N;++i){
        int t;
        cin >> cost[i] >> t;
        routes[i].resize(t);
        for(int j=0;j<t;++j){
            cin >> routes[i][j];
        }
    }
    /* from city A to i */
    vector<int> min_cost1(10001,100000);
    min_cost1[A]=0;
    /* from city i to B */
    vector<int> min_cost2(10001,100000);
    min_cost2[B]=0; 

    for(int i=0;i<N;++i){
        int curr_cost = cost[i];
        vector<int> curr_route = routes[i];
        
        int pos_a = (int)curr_route.size()+1; 
        int pos_b = -1;
        /* find the pos of A and B if they exist */
        for(int j=0;j<(int)curr_route.size();++j){
            if(curr_route[j]==A){
                pos_a=j;
            }
            else if(curr_route[j]==B){
                pos_b=j;
            }
        }

        for(int j=0;j<(int)curr_route.size();++j){
            if(pos_a <= j){
                min_cost1[curr_route[j]] = min(min_cost1[curr_route[j]], curr_cost);
            }
            if(j <= pos_b){
                min_cost2[curr_route[j]] = min(min_cost2[curr_route[j]], curr_cost);
            }
        }
    }

    int res = 100000;
    for(int i=1;i<=10000;++i){
        res = min(res,min_cost1[i]+min_cost2[i]);
    }

    if(res==100000)
        res=-1;
    cout << res << endl;
    return 0;
}
