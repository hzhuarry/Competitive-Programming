#include <bits/stdc++.h>
using namespace std;

#define ar array

int N;
ar<int,2> cows[10000];

bool cmp(const ar<int,2>& a, const ar<int,2>& b) {
    if(a[1] == b[1])
        return a[0] < b[0];
    return a[1] > b[1];
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ifstream cin("msched.in");
    ofstream cout("msched.out");

    cin >> N;
    for(int i=0; i<N; ++i)
        cin >> cows[i][0] >> cows[i][1];
    sort(cows, cows+N, cmp);

    int curr_cow = 0, res = 0;
    priority_queue<int> pq;

    for(int t=10000; t>=1; --t) {
        while(curr_cow < N and t <= cows[curr_cow][1]) {
            pq.push(cows[curr_cow][0]);
            ++curr_cow;
        }

        if(!pq.empty()) {
            res += pq.top();
            pq.pop();
        }
    }
    cout << res << endl;
    return 0;
}


