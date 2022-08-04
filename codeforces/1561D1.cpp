//Let dp[i] ways to move from n to i
//Transition:
//- dp[i] += sum dp[i+1] to dp[n]
//- dp[i] += sum dp[i*j] to dp[i*j+j-1]
//  (for x/z to have i as a result, x >= 2*i)
#include <iostream>
#include <cstring>
using namespace std;
int MOD;
int add(int a, int b){
    return ((long long)a+b)%MOD;
}

int sub(int a, int b){
    return (((long long)a-b)%MOD+MOD)%MOD;
}

int main(){
    int n; cin >> n >> MOD;
    int dp[n+2]; memset(dp,0,sizeof(dp)); //dp[i] = prefix sum from n to i;
    dp[n+1] = 0;
    dp[n] = 1;
    for(int i=n-1; i>0; i--){
        //derived from subtraction
        dp[i] = dp[i+1];

        //derived from the floor division
        //by summing dp[i*j] to dp[i*j + j-1]
        for(int j=2; i*j<=n; j++){
            dp[i] = add(dp[i],sub(dp[i*j],dp[min(i*j+j,n+1)]));
        }

        //adding the previous values
        dp[i] = add(dp[i],dp[i+1]);
    }
    cout << sub(dp[1],dp[2]) << "\n";
}