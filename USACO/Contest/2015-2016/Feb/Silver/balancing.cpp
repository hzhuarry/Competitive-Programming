#include <bits/stdc++.h>
using namespace std;

#define ar array
#define end \n

const int MX = 1000;
int N, ans=MX;
ar<int,2> points[MX];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    ifstream cin("balancing.in");
    ofstream cout("balancing.out");

    cin >> N;
    for(int i=0; i<N; ++i)
        cin >> points[i][0] >> points[i][1];
    sort(points, points+N);

    for(int i=0; i<N-1; ++i){
        /* first sweep with vertical line to the right of the first point */
        int x = points[0][0], y = points[i][1];
        int upper_left=0, upper_right=0, lower_left=0, lower_right=0;
        for(int j=0; j<N; ++j){
            if(points[j][1] > y){
                if(points[j][0] > x){
                    ++upper_right;
                }
                else{
                    ++upper_left;
                }
            }
            else{
                if(points[j][0] > x){
                    ++lower_right;
                }
                else{
                    ++lower_left;
                }
            }
        }
        ans = min(ans, max({lower_left, lower_right, upper_left, upper_right}));

        /* sweep a vertical line */ 
        for(int j=1; j<N-1; ++j){
            if(points[j][1] > y){
                --upper_right;
                ++upper_left;
            }
            else{
                --lower_right;
                ++lower_left;
            }
            ans = min(ans, max({lower_left, lower_right, upper_left, upper_right}));
        }
    }
    cout << ans << endl;
    return 0;
}
