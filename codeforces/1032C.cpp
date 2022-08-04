#include <iostream>
#include <cstring>
using namespace std;

int main(){
    int n; cin >> n;
    int a[n]; for(int i=0; i<n; i++) cin>> a[i];
    short dp[n][5]; memset(dp,-1,sizeof(dp)); memset(dp[0],1,sizeof(dp[0]));
    for(int i=1; i<n; i++){
        for(int j=0; j<5; j++){
            if(a[i]>a[i-1]){
                for(int k=j-1; k>=0; k--){
                    if(dp[i-1][k]!=-1){
                        dp[i][j]=k;
                        break;
                    }
                }
            } else if(a[i]<a[i-1]){
                for(int k=j+1; k<5; k++){
                    if(dp[i-1][k]!=-1){
                        dp[i][j]=k;
                        break;
                    }
                }
            } else {
                for(int k=0; k<5; k++){
                    if(k==j) continue;
                    if(dp[i-1][k]!=-1){
                        dp[i][j]=k;
                        break;
                    }
                }
            }
        }
    }
    for(int i=0; i<5; i++){
        if(dp[n-1][i]!=-1){
            int ans[n];
            int temp2=i,temp1=n-1;
            while(temp1>=0){
                ans[temp1]=temp2+1;
                temp2=dp[temp1--][temp2];
            }
            for(int i=0; i<n; i++) cout << ans[i] << " ";
            return 0;
        }
        
    }
    cout << "-1\n";
}