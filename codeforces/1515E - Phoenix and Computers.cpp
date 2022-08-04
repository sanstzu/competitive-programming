#include <iostream>
#include <cstring>
#pragma GCC optimize ("unroll-loops")
#pragma GCC optimize ("O3")
#pragma GCC target ("sse,sse2,sse3,ssse3,sse4,abm,avx,avx2,fma,mmx,tune=native")
using namespace std;
int mod;
// add, stick and merge in DP cc (connected components)
// dp[i][j] = i elements with j connect components

inline int a(int a, int b){
    return ((long long)a+b)%mod;
}

inline int m(int a, int b){
    return ((long long)a*b)%mod;
}
int main(){
    int n; cin >> n >> mod;
    int dp[n+15][n+15]; memset(dp,0,sizeof(dp));
    dp[0][0]=1;
    int ans = 0; 
    for(int i=0; i<n; i++){
        for(int j=0; j<=i; j++){
            //add a new connected component
            dp[i+1][j+1] = a(dp[i+1][j+1],m(dp[i][j],j+1)); // newcc - cc1 -cc2 -...

            //stick a new member to a connected component
            dp[i+1][j] = a(dp[i+1][j],m(dp[i][j],2*j)); // newmember+cc1 - cc2 - cc3 ...
            dp[i+2][j] = a(dp[i+2][j],m(dp[i][j],2*j)); // newmember+gap+cc1 - cc2 - cc3...

            //merge two existing connected components
            if(j>0){
                dp[i+2][j-1] = a(dp[i+2][j-1], m(dp[i][j],2*(j-1))); // cc1 + newmember + gap + cc2 - cc3 - ...
                dp[i+3][j-1] = a(dp[i+3][j-1], m(dp[i][j],j-1)); // cc1 + gap + newmember + gap + cc2 - cc3 ...
            }
        }
    }
    cout << dp[n][1] << "\n";
}