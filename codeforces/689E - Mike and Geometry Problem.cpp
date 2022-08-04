#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <cmath>
#include <queue>
#define f first
#define s second
#pragma GCC optimize ("unroll-loops")
#pragma GCC optimize ("O3")
#pragma GCC target ("sse,sse2,sse3,ssse3,sse4,abm,avx,avx2,fma,mmx,tune=native")
using namespace std;
typedef pair<int,int> pii;
const int SZ=200069;
const int MOD = 1e9+7;
int fac[SZ];
int ifac[SZ];

inline int MUL(int a, int b){ return ((long long)a*b)%MOD;}
inline int ADD(int a, int b){ return ((long long)a+b)%MOD;}
inline int comb(int n, int k){ return (n>=k?MUL(fac[n],MUL(ifac[n-k],ifac[k])):0);}

int fp(int a, int b){
    if(b==0) return 1;
    if(b%2) return MUL(a,fp(a,b-1));
    else {
        int ans = fp(a,(b>>1));
        return MUL(ans,ans);
    }
}

void init(){
    fac[0]=ifac[0]=1;
    for(int i=1; i<SZ; i++){
        fac[i]=MUL(fac[i-1],i);
        ifac[i] = MUL(ifac[i-1],fp(i,MOD-2));
    }
}

int main(){
    init();
    int n,k; cin >> n >> k;
    priority_queue<pii,vector<pii>,greater<pii>> pq;
    for(int i=0; i<n; i++){
        int l,r; cin >> l >> r;
        pq.push({l,1});
        pq.push({r+1,-1});
    }
    long long ans = 0;
    int cnt =0;
    int prev=0;
    while(pq.size()){
        pii temp=pq.top(); pq.pop();
        ans=ADD(ans,MUL(comb(cnt,k),(temp.f-prev)));
        prev=temp.f;
        if(temp.s==-1) cnt--;
        else cnt++;
    }
    cout << ans << "\n";
}