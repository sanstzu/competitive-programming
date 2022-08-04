#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int main(){
    int n; cin >> n;
    int arr[n]; for(int i=0; i<n; i++) cin >> arr[i];
    int dp[5000][5000][2]; memset(dp,0,sizeof(dp));
    for(int wth=2; wth<=n; wth++){
        for(int i=0; i<=n-wth; i++){
            dp[i][i+wth-1][0]=min((arr[i+wth-1]!=arr[i])+dp[i+1][i+wth-1][1],(arr[i+1]!=arr[i])+dp[i+1][i+wth-1][0]);
            dp[i][i+wth-1][1]=min((arr[i+wth-1]!=arr[i])+dp[i][i+wth-2][0],(arr[i+wth-1]!=arr[i+wth-2])+dp[i][i+wth-2][1]);

        }
    }
    cout << min(dp[0][n-1][0],dp[0][n-1][1]) << "\n";
}