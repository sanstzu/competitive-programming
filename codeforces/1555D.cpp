#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n, m; cin >> n >> m;
    int arr[n]; for(int i=0; i<n; i++){
        char temp; cin >> temp;
        arr[i] = temp - 'a';
    }
    int dp[n+1][6]; memset(dp[0],0,sizeof(dp[0]));
    for(int i=1; i<=n; i++){
        for(int j=0; j<3; j++){
            dp[i][j] = dp[i-1][j] + (arr[i-1]!=((i+2+j)%3));
        }
        for(int j=3; j<6; j++){
            dp[i][j] = dp[i-1][j] + (arr[i-1]!=(((2+j-i)%3)+3)%3);
        }
    }
    for(int i=0; i<m; i++){
        int a,b; cin >> a >> b;
        int ans = 2e9;
        for(int j=0; j<6; j++){
            ans = min(ans, dp[b][j]-dp[a-1][j]);
        }
        cout << ans << "\n";
    }
}