#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <bitset>
#pragma GCC optimize ("unroll-loops")
#pragma GCC optimize ("O3")
#pragma GCC target ("sse,sse2,sse3,ssse3,sse4,abm,avx,avx2,fma,mmx,tune=native")
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    int t; cin >> t;
    while(t--){
        int n,m,k; cin >> n >> m >> k;
        bitset<10069> bm[100][100];
        for(int i=0; i<100; i++){
            for(int j=0; j<100; j++){
                bm[i][j]=0;
            }
        }
        bm[0][0][0]=true;
        for(int dist = 1; dist <= (n+m-2); dist++){
            for(int row = min(n-1,dist); row>=0; row--){
                if(dist-row<0)break;
                if(row>0)bm[row][dist-row]|=(bm[row-1][dist-row]<<(dist-row+1));
                if(dist-row>0)bm[row][dist-row]|=(bm[row][dist-row-1]<<(row+1));
            }
        }
        if((bm[n-1][m-1][k])){
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
}