/*
ID: hzhu7271 
LANG: C++
TASK: sprime
*/

#include <bits/stdc++.h>
using namespace std;

#define pb push_back
using ll = long long;

/* FILE IO */
void setIO(string filename = "") {
    ios_base::sync_with_stdio(0); cin.tie(0);
    if ((int)filename.size()) { /* USACO */
        freopen((filename+".in").c_str(), "r", stdin);
        freopen((filename+".out").c_str(), "w", stdout);
    }
}

int N;

bool isPrime(int n){
    for(int i=2;i*i<=n;++i){
        if(n%i==0)
            return 0;
    }
    return 1;
}

void next_prime(int num,int cnt){
    if(cnt==0){
        cout << num << endl;
        return;
    }
    num*=10;
    if(isPrime(num+1))
        next_prime(num+1,cnt-1);
    if(isPrime(num+3))
        next_prime(num+3,cnt-1);
    if(isPrime(num+7))
        next_prime(num+7,cnt-1);
    if(isPrime(num+9))
        next_prime(num+9,cnt-1);
}

int main() {
    setIO("sprime");
    cin >> N;
    if(N==1){
        cout << 2 << endl;
        cout << 3 << endl;
        cout << 5 << endl;
        cout << 7 << endl;
    }
    else{
        --N;
        next_prime(2,N);
        next_prime(3,N);
        next_prime(5,N);
        next_prime(7,N);
    }
    return 0;
}
