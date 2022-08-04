#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t; cin >> t;
    while(t--){
        int n;cin >> n;
        int arr[n];
        for(int i=0; i<n; i++){
            cin >> arr[i];
        }
        int dp[n];
        int ans=-1;
        for(int i=n-1; i>=0; i--){
            if(i+arr[i]>=n){
                dp[i]=arr[i];
            } else {
                dp[i] = arr[i]+dp[i+arr[i]];
            }
            ans=max(ans,dp[i]);
        }
        cout << ans << "\n";
    }
}