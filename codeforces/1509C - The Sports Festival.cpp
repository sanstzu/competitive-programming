#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int main(){
    int n; cin >> n;
    int arr[n]; for(int i=0; i<n; i++) cin >> arr[i];
    sort(arr,arr+n);
    long long dp[n][n]; memset(dp,0,sizeof(dp));
    for(int w=2; w<=n; w++){
        for(int l=0; l<n-w+1; l++){
            int r = l+w-1;
            dp[l][r]=min(dp[l+1][r],dp[l][r-1])+(long long)arr[r]-arr[l];
        }
    }
    cout << dp[0][n-1] << "\n";
}

/*
Proof:
Assume that the current sequence is A. If we want to select
i-th member on the next round, such that min(A) < s_i < max(A),
it is proven that the sum of d is not the minimum, as we can swap
the position of the member that has the speed of min(A) or max(A)
which is lower than the current sum of dicrepancy.

Hence, in order to achieve minimum sum of discrepancy, we must
take the i-th member such that s_i <= min(A) or s_i>= max(A).
*/