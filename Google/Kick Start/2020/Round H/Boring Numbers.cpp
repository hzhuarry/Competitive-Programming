#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll pow_five[20];

ll go(ll x) {
    string ss = to_string(x);
    int n = (int)ss.size();
    ll ans = 0;

    /* the total number of boring numbers from length 1 to n-1 */
    for(int i=1; i<n; ++i) {
        ans += pow_five[i];
    }

    /* num of boring numbers of same length as x but the first index is less than ss[0] */
    ans += ((ss[0] - '0') / 2LL) * pow_five[n-1];

    /* fix the ith prefix of x */
    for(int i=0; i<n; ++i) {
        int c = ss[i] - '0';

        /* if the prefix isn't boring, then break */
        if((c % 2) != ((i + 1) % 2))
            break;

        /* if i==n-1 then all the digits are fixed and ans only increments by one since x is a boring number */
        if(i == n - 1) {
            ++ans;
        }
        else {
            int c2 = ss[i + 1] - '0';
            ll cnt;
            if(((i + 2) % 2) == 1) {
                cnt = c2 / 2;
            }
            else {
                cnt = (c2 + 1) / 2;
            }
            ans += cnt * pow_five[n - i - 2];
        }
    }
    return ans;
}

void solve() {
    ll L, R;
    cin >> L >> R;
    cout << go(R) - go(L-1) << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    for(int i=0; i<=18; ++i) {
        if(i==0)
            pow_five[i] = 1;
        else
            pow_five[i] = pow_five[i-1] * 5;
    }
    int T;
    cin >> T;
    for(int tc=1; tc<=T; ++tc) {
        cout << "Case #" << tc << ": ";
        solve();
    }
    return 0;
}


