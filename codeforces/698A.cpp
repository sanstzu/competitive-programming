#include <bits/stdc++.h>
using namespace std;
int arr[101];
int dp[101][3]; //[0]=nothing,[1]=contest,[2]=gym
const int INF=2e9;

int main(){
    int n; cin >> n;
    for(int i=1; i<=n; i++)cin >> arr[i];
    for(int i=1; i<=n; i++){
        dp[i][0]=min(dp[i-1][0],min(dp[i-1][1],dp[i-1][2]))+1;
        switch (arr[i]){
            case 3:
            dp[i][1]=min(dp[i-1][0],dp[i-1][2]);
            dp[i][2]=min(dp[i-1][0],dp[i-1][1]);
            break; case 2:
            dp[i][2]=min(dp[i-1][0],dp[i-1][1]);
            dp[i][1]=INF;
            break; case 1:
            dp[i][2]=INF;
            dp[i][1]=min(dp[i-1][0],dp[i-1][2]);
            break; case 0:
            dp[i][2]=INF;
            dp[i][1]=INF;
        }
        
    }
    /*
    for(int i=1;i<=n;i++){
        for(int j=0; j<3; j++){
            cout << dp[i][j] << " ";
        }
        cout << "\n";
    }
    */
    cout << min(dp[n][0],min(dp[n][1],dp[n][2]));
}