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
 
// 1 0 0 0 0 0 0 0 0 0 1 1

int main(){
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        int arr[n]; for(int i=0; i<n; i++) cin >> arr[i];
        int pref[n]; pref[0]=arr[0];
        for(int i=1; i<n; i++){
            pref[i]=pref[i-1]^arr[i];
        }
        bool found=false;
        for(int i=0; i<n-1 && !found; i++){
            for(int j=i+1; j<n && !found; j++){
                if((pref[i]==pref[n-1] || pref[n-1]==0) && pref[j]==0) found=true;
            }
        }
        cout << (found?"YES\n":"NO\n");
    }
}