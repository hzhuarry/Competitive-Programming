#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define ar array

typedef long long ll;
typedef string str;

const int maxn = 2e5;
int N,Q;
int x[maxn],ft[maxn+1],ans[maxn];
vector<ar<int,2>> q_a[maxn];
map<int,int> last_occur;

void upd(int i,int x){
    for(++i;i<=N;i+=i&-i){
        ft[i]+=x;
    }
}

int query(int i){
    int res=0;
    for(;i>0;i-=i&-i){
        res+=ft[i];
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> Q;
    for(int i=0;i<N;++i){
        cin >> x[i];
    }
    for(int i=0;i<Q;++i){
        int l,r;
        cin >> l >> r;
        --l,--r;
        q_a[r].push_back({l,i});
    }
    for(int i=0;i<N;++i){
        if(last_occur.find(x[i])!=last_occur.end())
            upd(last_occur[x[i]],-1);
        upd(i,1);
        for(auto u : q_a[i]){
            ans[u[1]] = query(N) - query(u[0]);
        }
        last_occur[x[i]]=i;
    }
    for(int i=0;i<Q;++i){
        cout << ans[i] << endl;
    }
    return 0;
}
