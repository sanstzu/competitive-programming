#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <cmath>
#pragma GCC optimize ("unroll-loops")
#pragma GCC optimize ("O3")
#pragma GCC target ("sse,sse2,sse3,ssse3,sse4,abm,avx,avx2,fma,mmx,tune=native")
using namespace std;
const int SZ = 1e7+5;
bool isPrime[SZ];
int SPF[SZ],SPFcount[SZ];
vector<int> prime;

void init(){
    for(int i=0; i<SZ; i++) isPrime[i]=true;
    isPrime[0]=isPrime[1]=false;
    for(int i=2; i<SZ; i++){
        if(isPrime[i]){
            prime.push_back(i);
            SPF[i]=i;
            SPFcount[i]=1;
        }
        for(int j=0; j<prime.size() && i*prime[j]<SZ && prime[j]<=SPF[i]; j++){
            isPrime[i*prime[j]]=false;
            SPF[i*prime[j]] = prime[j];
            if(SPF[i]==prime[j]){
                SPFcount[i*prime[j]]=SPFcount[i]*prime[j];
            } else {
                SPFcount[i*prime[j]]=prime[j];
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    init();
    int d[SZ]; memset(d,-1,sizeof(d));
    d[1]=1;
    int ans[SZ]; memset(ans,-1,sizeof(ans));
    ans[1]=1;
    for(int i: prime){
        int sum = 1; long long cur=1;
        while((cur*i)<SZ){
            cur=cur*i; sum+=cur;
            d[cur]=sum;
        }
    }
    for(int i=2; i<SZ; i++){
        if(d[i]==-1)d[i]=d[SPFcount[i]]*d[i/SPFcount[i]];
        if(d[i]<=SZ && ans[d[i]]==-1) ans[d[i]]=i;
    }
    
    int t; cin >> t;
    for(int i=0; i<t; i++){
        int temp; cin >> temp;
        cout << ans[temp] << "\n";
    }
    
}
/*
Sum of the divisors of x = p1^k1 * p2^k2 * ... * pi^ki
= product of all j (1 + pj + pj^2 + pj^3 + ... pj^kj) from 1 to i;
Proof:

Let a = (p1^k1 * p2^k2 * ... * pi^ki) and b = (pi+1^ki+1 * pi+2^ki+2 * ... * pj^kj)
where pm != pn for every m and n (m!=n)
Hence, a*b = (p1^k1 * p2^k2 * ... * pi^ki * pi+1^ki+1 * pi+2^ki+2 * ... * pj^kj)


d(a)    = product of all j (1 + pj + pj^2 + pj^3 + ... pj^kj) from 1 to i
d(b)    = product of all j (1 + pj + pj^2 + pj^3 + ... pj^kj) from i+1 to j
d(a*b)  = product of all j (1 + pj + pj^2 + pj^3 + ... pj^kj) from 1 to j
        = d(a) * d(b)

Hence it is proven that d(a*b) = d(a) * d(b) for all a and b such that GCD(a,b) = 1

We would need to calculate first the values of d(i) for i = p^k (k>0) so that we could
use the d(a*b) = d(a)*d(b) formula.
*/