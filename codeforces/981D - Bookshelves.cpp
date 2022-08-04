#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
const long long ulimit=((long long)1<<(long long)50)-1;
inline bool haveBit(long long x, long long y){
    //0 based indexing
    return (x&y)==y;
}
 
int main(){
    int n,k; cin >> n >> k;
    long long arr[n]; for(int i=0; i<n; i++)cin  >> arr[i];
    long long sum[n+1]; sum[0]=0; for(int i=1; i<=n; i++) sum[i]=sum[i-1]+arr[i-1];
    long long ans=0;
    for(int bit=55; bit>=0; bit--){
        long long temp = ans|((long long)1<<(long long)bit);
        bool dp[k+1][n+1]; memset(dp,0,sizeof(dp));
        dp[0][0]=1;
        for(int j=1; j<=k; j++){
            for(int i=j; i<=n; i++){
                for(int l=j-1; l<i; l++){
                    //cout << i << " " << j<< "\n";
                    if(!haveBit(sum[i]-sum[l],temp))continue;
                    dp[j][i]|=dp[j-1][l];
                }
            }
        }/*
        for(int i=0; i<=k; i++){
            for(int j=0; j<=n; j++){
                cout << dp[i][j] << " ";
            } cout << "\n";
        }*/
        if(dp[k][n])ans=temp;
    }
    cout << ans << "\n";
}