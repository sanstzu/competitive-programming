#include <iostream>
#include <map>
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
        long long sum=0; int arr[n];
        for(int i=0; i<n; i++){
            cin >> arr[i];
            sum+=(long long)arr[i];
        }
        if(sum%n){
            cout << "-1\n";
        } else {
            int div = (long long)sum/(long long)n;
            int ans = 0;
            for(int i=0; i<n; i++){
                if(arr[i]>div)ans++;
            }
            cout << ans << "\n";
        }
    }
}