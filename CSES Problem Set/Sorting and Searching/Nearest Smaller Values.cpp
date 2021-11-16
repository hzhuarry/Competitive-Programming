#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    int x[n];
    for(int i = 0; i < n; ++i) {
        cin >> x[i];
    }
    int ans[n];
    stack<int> st;
    for(int i = 0; i < n; ++i) {
        if(st.empty()) {
            ans[i] = 0;
            st.push(i);
        }
        else {
            while(st.size() and x[st.top()] >= x[i]) {
                st.pop();
            }
            if(st.empty()) {
                ans[i] = 0;
            }
            else {
                ans[i] = st.top() + 1;
            }
            st.push(i);
        }
    }
    for(int i = 0; i < n; ++i) {
        cout << ans[i] << " ";
    }
}


