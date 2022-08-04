#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <cmath>
#pragma GCC optimize ("unroll-loops")
#pragma GCC optimize ("O3")
#pragma GCC target ("sse,sse2,sse3,ssse3,sse4,abm,avx,avx2,fma,mmx,tune=native")
using namespace std;
int col[500][500],row[500][500];
vector<vector<int>> prevv,cur;
//col[i][j] = dist from (i,j) to (i,j+1)
//row[i][j] dist from (i,j) to (i+1,j)
int main(){
    ios::sync_with_stdio(0);
    cout.tie(0); cin.tie(0);
    int n,m,k; cin >> n >> m >> k;
    memset(col,0,sizeof(col));
    memset(row,0,sizeof(row));
    prevv.assign(500,vector<int>(500,0));
    cur.assign(500,vector<int>(500,0));
    for(int i=0;i<n; i++){
        for(int j=0; j<m-1; j++){
            cin >> col[i][j];
        }
    }
    for(int i=0;i<n-1; i++){
        for(int j=0; j<m; j++){
            cin >> row[i][j];
        }
    }
    if(k%2){
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                cout << "-1 ";
            } cout << "\n";
        }
        return 0;
    }
    for(int steps=1; steps<=(k>>1); steps++){
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                int minn=1e9;
                if(i>0){
                    minn=min(minn,row[i-1][j]+prevv[i-1][j]);
                }
                if(j>0){
                    minn=min(minn,col[i][j-1]+prevv[i][j-1]);
                }
                if(i<n-1){
                    minn=min(minn,row[i][j]+prevv[i+1][j]);
                }
                if(j<m-1){
                    minn=min(minn,col[i][j]+prevv[i][j+1]);
                }
                cur[i][j]=minn;
            }
        }
        prevv=cur;
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cout << prevv[i][j]*2 << " ";
        } cout << "\n";
    }
}