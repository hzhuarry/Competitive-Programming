#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

#define ll long long
#define x first
#define y second

template<class T> using oset = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

int N;
pair<int, int> coord[2500];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for(int i=0; i<N; ++i) {
        cin >> coord[i].x >> coord[i].y;
    }

    sort(coord, coord + N);

    ll ans = 0;
    for(int i=0; i<N; ++i) {
        oset<int> os;
        for(int j=i; j<N; ++j) {
            os.insert(coord[j].y);
            int ymin = min(coord[i].y, coord[j].y);
            int ymax = max(coord[i].y, coord[j].y);
            int num_of_coords = j - i + 1;
            int ymin_index = os.order_of_key(ymin);
            int ymax_index = os.order_of_key(ymax);
            /* number of rectangles = (number of ways to choose lower side of the rectangle) * (number of ways to choose upper side of rectangle) = 
             * (number of y coordinates <= ymin) * (number of y coordinates >= ymax) */
            ans += (ll)(ymin_index + 1) * (ll)(num_of_coords - ymax_index);
        }
    }

    cout << ans + 1 << '\n';
    return 0;
}

