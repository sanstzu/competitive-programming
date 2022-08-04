#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;
//sint n,k,l;
//int d[105];
//bool dp[105][105];

int main(){
    int t; cin>>t;
    while(t--){
        int n,k,l; cin >> n >> k >> l;
        int d[n]; for(int i=0; i<n; i++) cin >> d[i];
        bool dp[n+1][2*k]; //dp[i][j] = possible/not possible to reach i at time j%2k
        //tide at time j%2k = k - |k - j|
        memset(dp,0,sizeof(dp));
        memset(dp[0],1,sizeof(dp[0]));
        for(int i=0; i<n; i++){
            for(int j=0; j<4*k; j++){
                if(!dp[i][j%(2*k)]) continue;
                /* stay */ if(i>0 && (d[i-1] + k-abs(k-(j+1)%(2*k)))<=l) dp[i][(j+1)%(2*k)]=true;
                /* swim */ if((d[i] + k-abs(k-(j+1)%(2*k)))<=l) dp[i+1][(j+1)%(2*k)]=true;
            }
        }
        /*
        for(int i=0; i<=n; i++){
            for(int j=0; j<2*k;j++){
                cout << dp[i][j] << " ";
            } cout << "\n";
        }*/
        bool ans=0;
        for(int j=0; j<2*k; j++) ans|=dp[n][j];
        cout << (ans?"Yes\n":"No\n");
    }
}