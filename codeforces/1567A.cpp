#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <vector>
#include <string>
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
        char arr[n]; for(int i=0; i<n; i++) cin >> arr[i];
        char ans[n];
        for(int i=0; i<n; i++){
            if(arr[i]=='L' || arr[i]=='R'){
                ans[i] = arr[i];
            } else if (arr[i]=='U'){
                ans[i] = 'D';
            } else {
                ans[i] = 'U';
            }
            cout << ans[i];
        } cout << "\n";
    }
}

