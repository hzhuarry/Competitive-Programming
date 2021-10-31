#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int N, K, hay[(int)1e6];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ifstream cin("stacking.in");
    ofstream cout("stacking.out");

    cin >> N >> K;
    for(int i = 0; i < K; ++i) {
        int a, b;
        cin >> a >> b;
        --a;
        --b;
        hay[a]++;
        hay[b + 1]--;
    }

    vector<int> ans;
    for(int i = 0, sum = 0; i < N; ++i) {
        sum += hay[i];
        ans.push_back(sum);
    }
    sort(ans.begin(), ans.end());
    cout << ans[N / 2] << '\n';
}

