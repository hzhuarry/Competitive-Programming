#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin>>n;
    vector<int> v;
    for(int i=1;i<=n;++i){
        v.push_back(i);
    }
    for(int i=1;i<n;++i){
        int a;
        cin>>a;
        v.push_back(a);
    }
    int ans=0;
    for(int i=0;i<v.size();++i){
        //cool trick I learned from tmw
        ans^=v[i];
    }
    cout<<ans<<endl;
    return 0;
}
