#include <bits/stdc++.h>
using namespace std;

bool cmp(const pair<int,string>& a, const pair<int,string>& b) {
    if(a.first == b.first)
        return a.second < b. second;
    return a.first > b.first;
}

void solve() {
    int N; 
    cin >> N;
    vector<pair<int,string>> v(N);
    string s; getline(cin, s);
    for(int i=0; i<N; ++i) {
        getline(cin, s);
        set<char> se;
        for(char ch : s) {
            if(ch == ' ')
                continue;
            se.insert(ch);
        }
        v[i] = {(int)se.size(), s};
    }
    sort(v.begin(), v.end(), cmp);
    cout << v[0].second << endl;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1; 
    cin >> T;
    for(int i=1; i<=T; ++i) {
        cout << "Case #" << i << ": ";
        solve();
    }
    return 0;
}

