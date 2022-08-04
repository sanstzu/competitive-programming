#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;

bool stsmaller(string A, string B){
    int lena = A.length(), lenb = B.length(), mlen= min(lena,lenb);
    for(int i=0; i<mlen; i++){
        if(A[i]==B[i])continue;
        return A[i]<B[i];
    }
    return lena<=lenb;
}

int main(){
    int n; cin >> n;
    int c[n]; for(int i=0; i<n; i++) cin >> c[i];
    string str[n]; for(int i=0; i<n; i++) cin >> str[i];
    long long dp[n+1][2]; //dp[i][0] = not switching string i, dp[i][1] = switching string i
    for(int i=0; i<n+1; i++){
        for(int j=0; j<2; j++){
            dp[i][j]=1e16+9;
        }
    }
    dp[0][0]=0; dp[0][1]=c[0];
    string rv[2];
    rv[0]=str[0];
    reverse(rv[0].begin(), rv[0].end());
    for(int i=1; i<n; i++){
        rv[1]=str[i]; reverse(rv[1].begin(),rv[1].end());
        bool nn=stsmaller(str[i-1],str[i]), ns=stsmaller(str[i-1],rv[1]), sn=stsmaller(rv[0],str[i]), ss=stsmaller(rv[0],rv[1]);
        if(nn){
            dp[i][0]=min(dp[i][0],(long long)dp[i-1][0]);
        }
        if(ns){
            dp[i][1]=min(dp[i][1],(long long)dp[i-1][0]+c[i]);
        }
        if(sn){
            dp[i][0]=min(dp[i][0],(long long)dp[i-1][1]);
        }
        if(ss){
            dp[i][1]=min(dp[i][1],(long long)dp[i-1][1]+c[i]);
        }
        rv[0]=rv[1];
    }
    long long ans = min(dp[n-1][0],dp[n-1][1]);
    if(ans>1e16){
        ans=-1;
    }
    /*
    for(int i=0; i<n+1; i++){
        for(int j=0; j<2; j++){
            cout << dp[i][j] << " ";
        }
        cout << "\n";
    }
    */
    cout << ans << "\n";
}