#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <map>
#pragma GCC optimize ("unroll-loops")
#pragma GCC optimize ("O3")
#pragma GCC target ("sse,sse2,sse3,ssse3,sse4,abm,avx,avx2,fma,mmx,tune=native")
using namespace std;

int main(){
    int t; cin >> t;
    while(t--){
        int n; cin >> n; int arr[n];
        int minidx=0;
        for(int i=0; i<n; i++) {
            cin >> arr[i];
            if(arr[i]<arr[minidx]){
                minidx=i;
            }
        }
        if(minidx==0){
            cout << n-1 << "\n";
        } else {
            cout << n << "\n";
            cout << 1 << " " << minidx+1 << " " << arr[minidx] << " " << arr[minidx] << "\n";
        }
        for(int i=1; i<n; i++){
            cout << 1 << " " << i+1 << " " << arr[minidx] << " " << arr[minidx]+i << "\n";
        }
    }
}