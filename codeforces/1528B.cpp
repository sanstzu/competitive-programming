#include <iostream>
#include <map>
#include <cstring>
#include <vector>
#include <algorithm>
#include <deque>
#define f first
#define s second
#pragma GCC optimize ("unroll-loops")
#pragma GCC optimize ("O3")
#pragma GCC target ("sse,sse2,sse3,ssse3,sse4,abm,avx,avx2,fma,mmx,tune=native")
using namespace std;
vector<int> prime;
const int MOD = 998244353;
int d[1000001];

inline int mul(int a, int b){
    return ((long long)a*b)%MOD;
}

inline int add(int a, int b){
    return ((long long)a+b)%MOD;
}

void init(){
    for(int i=0; i<1000001; i++) d[i]=1;
    for(int i=2; i<1000001; i++){
        for(int j=1; i*j<1000001; j++){
            d[i*j]++;
        }
    }
}


int main(){
    init();
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n; cin >> n;
    long long dp[n+1]; dp[0]=0;
    for(int i=1; i<=n; i++){
        dp[i] = add(mul(dp[i-1],2),d[i]);
    }
    //cout << d(2) << "\n";
    cout << ((dp[n]-dp[n-1])%MOD+MOD)%MOD << "\n";
}