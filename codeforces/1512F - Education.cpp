#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <cmath>
#pragma GCC optimize ("unroll-loops")
#pragma GCC optimize ("O3")
#pragma GCC target ("sse,sse2,sse3,ssse3,sse4,abm,avx,avx2,fma,mmx,tune=native")
using namespace std;
int n,c;
vector<int> a,b;
int recur(int pos, int cash){
    
    //either increase pos or just buy immediately
    int rc = max(0, (c - cash + a[pos] -1)/a[pos]);
    if(pos==n-1) return rc;
    int rp = max(0, (b[pos] - cash + a[pos] -1)/a[pos]);
    int ans =min(rc,rp +1 + recur(pos+1,rp*a[pos]+cash-b[pos]));
    //cout << "recur(" << pos << "," << cash <<"): "<< ans  << "\n";
    //cout << "rp:" <<  rp << " rc:" << rc << "\n";
    return ans;
}

void solve(){
    cin >> n >> c;
    a.resize(n,0); b.resize(n-1,0);
    for(int i=0; i<n; i++) cin >> a[i];
    for(int i=0; i<n-1; i++) cin >> b[i];
    cout << recur(0,0) << "\n";
}

int main(){
    int t; cin >> t;
    while(t--){
        solve();
    }
}