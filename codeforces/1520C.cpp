#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#pragma GCC optimize ("unroll-loops")
#pragma GCC optimize ("O3")
#pragma GCC target ("sse,sse2,sse3,ssse3,sse4,abm,avx,avx2,fma,mmx,tune=native")
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        if(n==2){
            cout << "-1\n";
            continue;
        }
        int arr[n][n];
        int cnt=1;
        for(int i=0; i<n; i++){
            for(int j=i%2; j<n; j+=2){
                arr[i][j]=cnt++;
            }
        }
        for(int i=0; i<n; i++){
            for(int j=(i+1)%2; j<n; j+=2){
                arr[i][j]=cnt++;
            }
        }
        for(int i=0; i<n; i++){for(int j=0; j<n; j++) cout << arr[i][j] << " "; cout << "\n";}
    }
}