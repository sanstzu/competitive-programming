#include <iostream>
#include <algorithm>
using namespace std;
const int MOD = 1e9+7;
int fact[100001], ifact[100001];

inline int mul(int a, int b){
    return ((long long)a*b)%MOD;
}

inline int add(int a, int b){
    return ((long long)a+b)%MOD;
}

int fp(int a, int b){
    if(b==0) return 1;
    if(b%2) return mul(a,fp(a,b-1));
    else {
        int ans = fp(a,(b>>1));
        return mul(ans,ans);
    }
}

inline int c(int n, int k){
    return mul(fact[n],mul(ifact[n-k],ifact[k]));
}

inline int p(int n, int k){
    return mul(fact[n],ifact[n-k]);
}

void init(){
    fact[0]=1, ifact[0]=1;
    for(int i=1; i<100001; i++){
        fact[i]=fact[i-1]*i;
        ifact[i]=ifact[i-1]*fp(i,MOD-2);
    }
}

int main(){
    int n,m; cin >> n >> m;
    for(int i=)
}
