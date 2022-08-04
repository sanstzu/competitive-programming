#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#pragma GCC optimize ("unroll-loops")
#pragma GCC optimize ("O3")
#pragma GCC target ("sse,sse2,sse3,ssse3,sse4,abm,avx,avx2,fma,mmx,tune=native")
using namespace std;


int main(){
    string str; cin >> str;
    int n=str.length();
    int dp[n][n]; memset(dp,0,sizeof(dp));
    int ans[n+1]; memset(ans,0,sizeof(ans));
    for(int i=0; i<n; i++){
        dp[i][i]=1;
        ans[1]++;
        if(i<n-1 && str[i]==str[i+1]){dp[i][i+1]=2; ans[2]++;}
    }
    for(int w=3; w<=n; w++){
        for(int i=0; i<n-w+1; i++){
            if(dp[i+1][i+w-2]>0 && str[i]==str[i+w-1]){
                dp[i][i+w-1]=dp[i][i+(w>>1)-1]+1;
                ans[dp[i][i+w-1]]++;
            }
        }
    }
    int temp=0;
    for(int i=1; i<n+1; i++){
        temp+=ans[i];
    }
    for(int i=1; i<n+1; i++){
        cout << temp << ' ';
        temp-=ans[i];
    } cout << "\n";
}