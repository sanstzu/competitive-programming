#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
const int INF=9e5;
//dp[i][T] = minimum |T - ti|
// 2 2 4 4 4 5
int main(){
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        int arr[n+1]; for(int i=1; i<=n; i++)cin >> arr[i];
        sort(arr+1,arr+n+1);
        //for(int i=1; i<=n; i++)cout << arr[i] << " ";
        //cout << "\n";
        int dp[2*n+1][n+1]; for(int i=0; i<=2*n;i++)for(int j=0; j<=n; j++)dp[i][j]=INF;
        for(int i=0; i<=2*n; i++) dp[i][0]=0;
        
        for(int t=1; t<=2*n; t++){
            for(int i=1; i<=n; i++){
                dp[t][i]=min(dp[t-1][i],dp[t-1][i-1]+abs(t-arr[i]));
                //cout << "(" << t << "," << i << ")" << dp[t-1][i] << " " << dp[t-1][i-1]+abs(t-arr[i]) << "\n";
            }
            //cout << "\n";
        }
        /*
        for(int i=0; i<=2*n; i++){
            for(int j=0; j<=n; j++) cout << dp[i][j] << " ";
            cout << "\n";
        }
        */
        cout << dp[2*n][n] << "\n";
    }
}