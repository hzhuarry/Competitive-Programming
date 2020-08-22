#include <bits/stdc++.h>
using namespace std;

#define ar array

/* sort by second val */
bool cmp(ar<int,2>& a, ar<int,2>& b){
    if(a[1] == b[1])
        return a[0] < b[0];
    return a[1] < b[1];
}

const int MX = 2e5;
int n, k;
ar<int,2> movie[MX];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;
    for(int i=0; i<n; ++i)
        cin >> movie[i][0] >> movie[i][1];
    sort(movie, movie+n, cmp);

    int ans = 0;
    multiset<int> se;

    for(int i=0; i<n; ++i){
        bool use_prev=0;
        if(!se.empty()){
            /* try to use a previous person if possible rather than use another person */
            auto it = se.upper_bound(movie[i][0]);
            if(it != se.begin()){
                --it;
                if(*it <= movie[i][0]){
                    se.erase(it);
                    se.insert(movie[i][1]);
                    use_prev = 1;
                    ++ans;

                }
            } 
        }
        if((int)se.size()<k and !use_prev){
            /* if we didnt use someone previously, we just use another person to watch the movie */
            se.insert(movie[i][1]);
            ++ans;
        }
    }
    cout << ans << endl;
    return 0;
}
