#include <iostream>
#include <vector>
using namespace std;
const int MOD=1e9+7;
 
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int dp[200001][10]; // dp[i][j] total length of digit j after i operations
    for(int i=0; i<10; i++) dp[0][i]=1;
    for(int i=1; i<200001; i++){
        for(int j=0; j<10; j++){
            dp[i][j]=dp[i-1][(j+1)%10];
            if(j==9)dp[i][j]=(dp[i][j]+dp[i-1][1])%MOD;
        }
    }
    int t; cin >> t;
    while(t--){
        string n; int m; cin >> n >> m;
        int ans = 0;
        for(int i=0; i<n.length(); i++){
            ans = (ans+dp[m][(int)(n[i]-'0')])%MOD;
        }
        cout << ans << "\n";
    }
}