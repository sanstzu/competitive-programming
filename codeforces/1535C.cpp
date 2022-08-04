#include <iostream>
#include <map>
#include <cstring>
#include <vector>
#include <algorithm>
#pragma GCC optimize ("unroll-loops")
#pragma GCC optimize ("O3")
#pragma GCC target ("sse,sse2,sse3,ssse3,sse4,abm,avx,avx2,fma,mmx,tune=native")
using namespace std;


int main(){
    //ios::sync_with_stdio(0);
    //cin.tie(0); cout.tie(0);
    int t; cin >> t;
    while(t--){
        string str; cin >> str;
        int n = str.size();
        long long dp[n+1][2]; dp[0][0]=dp[0][1]=0;
        long long tmp = 0, qmcnt= 0;
        for(int i=0; i<n; i++){
            dp[i+1][0] = (str[i]=='0' || str[i]=='?')*(dp[i][1]+1);
            dp[i+1][1] = (str[i]=='1' || str[i]=='?')*(dp[i][0]+1);
            tmp += dp[i+1][0] + dp[i+1][1];
            if(str[i]=='?') qmcnt++;
            else qmcnt = 0;
            tmp -= qmcnt;
        }
        cout << tmp << "\n";
    }
}