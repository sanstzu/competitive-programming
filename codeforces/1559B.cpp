#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;
const int INF = 1e9;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        int arr[n+1]; for(int i=1; i<=n; i++){
            char temp; cin >> temp;
            switch(temp){
                case '?':
                    arr[i]=0;
                    break;
                case 'R':
                    arr[i]=1;
                    break;
                case 'B':
                    arr[i]=2;
                    break;
            }
        }

        int dp[n+1][2]; bool bt[n+1][2];
        for(int i=0; i<n+1; i++){
            dp[i][0]=dp[i][1]=INF;
        }
        dp[0][0]=dp[0][1]=0;
        for(int i=1; i<=n; i++){
            if(arr[i]==0 || arr[i]==1){
                if(dp[i-1][0]+1<dp[i-1][1]){
                    dp[i][0] = dp[i-1][0]+1;
                    bt[i][0] = 0;
                } else {
                    dp[i][0] = dp[i-1][1];
                    bt[i][0] = 1;
                }
            }

            if(arr[i]==0 || arr[i]==2){
                if(dp[i-1][1]+1<dp[i-1][0]){
                    dp[i][1] = dp[i-1][1]+1;
                    bt[i][1] = 1;
                } else {
                    dp[i][1] = dp[i-1][0];
                    bt[i][1] = 0;
                }
            }
        }
        /*
        for(int i=1; i<=n; i++){
            for(int j=0; j<2; j++){
                cout << dp[i][j] << " ";
            } cout << "\n";
        }*/
        vector<char> ans;
        int temp,curr;
        if(dp[n][0]<dp[n][1]){
            ans.push_back('R');
            curr = n-1;
            temp = (int)bt[n][0];
        } else {
            ans.push_back('B');
            curr = n-1;
            temp = (int)bt[n][1];
        }
        while(curr>0){
            if(temp==0){
                ans.push_back('R');
            } else {
                ans.push_back('B');
            }
            temp = bt[curr][temp];
            curr--;
        }
        for(int i=n-1; i>=0; i--){
            cout << ans[i];
        } cout << "\n";
    }
}