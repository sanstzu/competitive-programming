#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <vector>
#include <string>
#pragma GCC optimize ("unroll-loops")
#pragma GCC optimize ("O3")
#pragma GCC target ("sse,sse2,sse3,ssse3,sse4,abm,avx,avx2,fma,mmx,tune=native")
using namespace std;


int main(){
    //ios::sync_with_stdio(0);
    //cin.tie(0); cout.tie(0);
    int t; cin >> t;
    while(t--){
        string str; cin>>str;
        int n = str.length();
        //cout << n << "\n";
        reverse(str.begin(),str.end());
        //cout << "z\n";
        int dp[n+1][2][2]; //dp[i][0] = not a +1 donor, [1] = +1 donor
        //cout << "y\n";
        //dp[i][j][0] = not a +1 recipient, [1] = a +1 recipient
        dp[0][0][0] = 0;
        dp[0][0][1] = 0;
        dp[0][1][0] = 0;
        dp[0][1][1] = 0;
        //cout << "a\n";
        for(int i=0; i<n; i++){
            dp[i+1][0][0] = (int)(str[i]-'0')+1;
            dp[i+1][0][1] = (i>1?(str[i]-'0'):0);
            dp[i+1][1][0] = (int)('9'-str[i]);
            dp[i+1][1][1] = (i>1? ((int)('9'-str[i])+1): 0);
            //cout << "for i: " << i << " = " << dp[i+1][1][1] << "\n";
        }
        //cout << "b\n";
        long long ans = 0;
        for(int i=0; i<(1<<(max(0,n-2))); i++){
            long long temp = 1;
            for(int j=0; j<n; j++){
                //if -ith bit from the right is active, therefore i is a +1 donor
                temp *= dp[j+1][(i>>j)&1][ (j>1? (i>>(j-2)):0)&1 ];
                //cout << "for i: " << i << " for j: " << j << " = " << dp[j+1][(i>>j)&1][ (j>1? (i>>(j-2)):0)&1 ] << "\n";
            }
            ans+= temp;
        }
        cout << ans-2 << "\n";
    }
}

