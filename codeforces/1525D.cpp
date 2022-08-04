#include <iostream>
#include <queue>
#include <cstring>
#include <vector>
#include <algorithm>
#include <deque>
#define f first
#define s second
#pragma GCC optimize ("unroll-loops")
#pragma GCC optimize ("O3")
#pragma GCC target ("sse,sse2,sse3,ssse3,sse4,abm,avx,avx2,fma,mmx,tune=native")
using namespace std;

int main(){
    int n; cin >> n;
    vector<int> arr,narr;
    for(int i=0; i<n; i++){
        int temp; cin >> temp;
        if(temp) arr.push_back(i);
        else narr.push_back(i);
    }
    int ufree = arr.size();
    int free = n-arr.size();
    int dp[free+1][arr.size()+1]; memset(dp,0,sizeof(dp));
    for(int i=1; i<=free; i++){
        for(int j=1; j<=min(i,ufree); j++){
            if(i>j){
                dp[i][j] = min(dp[i-1][j], dp[i-1][j-1] + abs(arr[j-1]-narr[i-1]));
            } else {
                dp[i][j] = dp[i-1][j-1] + abs(arr[j-1]-narr[i-1]);
            }
        }
    }
    cout << dp[free][ufree] << "\n";
}