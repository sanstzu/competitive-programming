#include <iostream>
#pragma GCC optimize ("unroll-loops")
#pragma GCC optimize ("O3")
#pragma GCC target ("sse,sse2,sse3,ssse3,sse4,abm,avx,avx2,fma,mmx,tune=native")
using namespace std;

int main(){
    int n,m,k; cin >> n >> m >> k;
    char arr[n][m];
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> arr[i][j];
        }
    }
    for(int col=0; col<m; col++){
        int ans = 0;
        for(int row = 1; row<n; row++){
            if(col+row<m && arr[row][col+row]=='L')ans++;
            if(col-row>=0 && arr[row][col-row]=='R')ans++;
        }
        for(int row = 2; row<n; row+=2){
            if(arr[row][col]=='U')ans++;
        }
        cout << ans << " ";
    }
}