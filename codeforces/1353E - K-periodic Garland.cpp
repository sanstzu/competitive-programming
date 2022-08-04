#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>

#pragma GCC optimize ("unroll-loops")
#pragma GCC optimize ("O3")
#pragma GCC target ("sse,sse2,sse3,ssse3,sse4,abm,avx,avx2,fma,mmx,tune=native")
using namespace std;

/*


*/

int main(){
    ios::sync_with_stdio(0);
    cout.tie(0); cin.tie(0);
    int t; cin >> t;
    while(t--){
        int n,k; cin >> n >> k;
        int psum[n+1]; psum[0]=0;
        int dp[n];
        bool arr[n];
        for(int i=0; i<n; i++){
            char temp; cin >> temp;
            arr[i]=temp-'0';
            psum[i+1]=psum[i]+arr[i];
        }
        int ans=psum[n];
        for(int i=0; i<n; i++){
            if(i<k)dp[i]=psum[i]+(!arr[i]);
            else dp[i]=min(dp[i-k]+psum[i]-psum[i-k+1]+(!arr[i]),psum[i]+(!arr[i]));
            ans=min(ans,dp[i]+psum[n]-psum[i+1]);
        }
        cout << ans << "\n";
    }

}