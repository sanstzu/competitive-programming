#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <cmath>
#pragma GCC optimize ("unroll-loops")
#pragma GCC optimize ("O3")
#pragma GCC target ("sse,sse2,sse3,ssse3,sse4,abm,avx,avx2,fma,mmx,tune=native")
using namespace std;
using namespace std;

int main(){
    int t; cin >> t;
    while(t--){
        int n,k; cin >> n >> k;
        int arr[n]; for(int i=0; i<n; i++) cin>> arr[i];
        int ptr=0;
        while(k>0 && ptr<n-1){
            if(arr[ptr]==0){ptr++; continue;}
            else {
                arr[ptr]--; arr[n-1]++;
                k--;
            }
        }
        for(int i=0; i<n; i++){
            cout << arr[i] << " ";
        } cout << "\n";
    }
}