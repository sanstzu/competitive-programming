#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#pragma GCC optimize ("unroll-loops")
#pragma GCC optimize ("O3")
#pragma GCC target ("sse,sse2,sse3,ssse3,sse4,abm,avx,avx2,fma,mmx,tune=native")

using namespace std;
int MOD;

inline add(int a, int b){
    return (a+b)%MOD;
}
int main(){
    int n,m,bg; cin >> n >> m >> bg >> MOD;
    int arr[n]; for(int i=0; i<n; i++) cin >> arr[i];
    int dp[505][505]; memset(dp,0,sizeof(dp));
    dp[0][0] = 1; //dp[lines of code][bugs] = ways
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            for(int k=0; k<(bg-arr[i]+1); k++){
                dp[j+1][k+arr[i]]+=dp[j][k]; dp[j+1][k+arr[i]]%=MOD;
            }
        }
    }
    /*
    for(auto i: a){
        for(auto j: i){
            cout << j << " ";
        } cout << "\n";
    }
    */
    int ans = 0;
    for(int k=0; k<=bg; k++) ans = add(ans,dp[m][k]);
    cout << ans << "\n";
}