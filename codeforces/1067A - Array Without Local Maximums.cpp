#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
int arr[100000],n;
const int MOD=998244353;

int add(int a, int b){
    return (((long long)a+(long long)b)+MOD)%MOD;
}

int main(){
    cin >> n;
    for(int i=0; i<n; i++) {cin >> arr[i];if(arr[i]!=-1)arr[i]--;}
    int cur[200][2],prev[200][2]; //dp[i][j][flag] = ways to make array with the length of i that ends on j. flag = 0 if arr[i]>=arr[i-1] and reverse.
    memset(cur,0,sizeof(cur));
    memset(prev,0,sizeof(prev));
    prev[0][1]=1;
    for(int i=0; i<n; i++){
        if(arr[i]==-1){
            int sum[201][2];
            memset(sum,0,sizeof(sum));
            for(int j=0; j<2; j++){
                for(int k=1; k<=200; k++){
                    sum[k][j]=add(sum[k-1][j],prev[k-1][j]);
                }
            }
            for(int k=0; k<200; k++){
                cur[k][0]=add(cur[k][0],add(sum[k][1],sum[k][0]));
                cur[k][1]=add(cur[k][1],prev[k][0]);
                cur[k][1]=add(cur[k][1],add(sum[200][1],0-sum[k][1]));
            }
        } else {
            int k=arr[i];
            for(int j=0; j<k; j++){
                cur[k][0]=add(cur[k][0],add(prev[j][1],prev[j][0]));
            }
            cur[k][1]=add(cur[k][1],prev[k][0]);
            for(int j=k; j<200; j++){
                cur[k][1]=add(cur[k][1],prev[j][1]);
            }
        }
        for(int i=0; i<200; i++){
            for(int j=0; j<2; j++){
                //cout << cur[i][j] << " ";
                prev[i][j]=cur[i][j];
            }
            //cout << "\n";
        }
        memset(cur,0,sizeof(cur));
    }
    int ans=0;
    if(arr[n-1]==-1){
        for(int i=0; i<200; i++){
            ans=add(ans,prev[i][1]);
        }
    } else {
        ans=prev[arr[n-1]][1];
    }
    cout << ans << "\n";
}