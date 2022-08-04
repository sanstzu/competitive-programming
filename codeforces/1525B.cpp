#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#define f first
#define s second
#pragma GCC optimize ("unroll-loops")
#pragma GCC optimize ("O3")
#pragma GCC target ("sse,sse2,sse3,ssse3,sse4,abm,avx,avx2,fma,mmx,tune=native")
using namespace std;

int main(){
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        int arr[n]; for(int i=0; i<n; i++) cin >> arr[i];
        int cmax=0, cnt=0, scnt=0;
        for(int i=0; i<n; i++){
            cmax=max(cmax,arr[i]);
            if(cmax==i+1)cnt++;
        }
        if(cnt==n){
            cout << "0\n";
        } else if(cnt>1){
            cout << 1+!(arr[0]==1 || arr[n-1]==n) << "\n";
        } else {
            cout << 2+(arr[0]==n && arr[n-1]==1) << "\n";
        }
    }
}