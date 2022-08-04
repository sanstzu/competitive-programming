#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <bitset>
#pragma GCC optimize ("unroll-loops")
#pragma GCC optimize ("O3")
#pragma GCC target ("sse,sse2,sse3,ssse3,sse4,abm,avx,avx2,fma,mmx,tune=native")
using namespace std;

int main(){
    int n; cin >> n;
    long long a[n], b[n]; for(int i=0; i<n; i++) cin >> a[i]; for(int i=0; i<n; i++) cin >> b[i];
    long long pref[n+1]; pref[0]=0;
    for(int i=1; i<=n; i++){
        pref[i]=pref[i-1]+a[i-1]*b[i-1];
    }
    long long dp[n][n]; memset(dp,0,sizeof(dp));
    long long ans = pref[n];
    for(int i=0; i<n; i++){
        dp[i][i]=pref[n];
        if(i==n-1) break;
        dp[i][i+1]=pref[n]-a[i]*b[i]-a[i+1]*b[i+1]+a[i]*b[i+1]+a[i+1]*b[i];
        ans=max(dp[i][i+1],ans);
    }
    
    for(int len=3; len<=n; len++){
        for(int l=0; l<n-len+1; l++){
            int r=l+len-1;
            dp[l][r]=dp[l+1][r-1]-a[l]*b[l]-a[r]*b[r]+a[l]*b[r]+a[r]*b[l];
            ans=max(ans,dp[l][r]);
        }
    }
    cout << ans << "\n";
}