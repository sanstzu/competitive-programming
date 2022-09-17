#include <iostream>
#include <cstring>
using namespace std;

int main(){
    long long n,c[3];
    cin >> n >> c[0] >> c[1] >> c[2];
    long long prefsum[n+1]; prefsum[0] = 0;
    int arr[n];
    for(int i=0; i<n; i++) cin >> arr[i];
    for(int i=0; i<n; i++){
        prefsum[i+1] = arr[i] + prefsum[i];
    }
    bool dp[n][3]; memset(dp,0,sizeof(dp));
    for(int i=0; i<3; i++){
        int ptr_l = 0;
    }

}