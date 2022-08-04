#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <vector>
#include <string>
#define f first
#define s second
#pragma GCC optimize ("unroll-loops")
#pragma GCC optimize ("O3")
#pragma GCC target ("sse,sse2,sse3,ssse3,sse4,abm,avx,avx2,fma,mmx,tune=native")
using namespace std;

bool sf(pair<int,int> a, pair<int,int> b){
    if(a.f<b.f){
        return true;
    } else if(a.f>b.f){
        return false;
    } else {
        if(a.s>b.s){
            return true;
        } else {
            return false;
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        pair<int,int> arr[n]; //{maxpow, size k}
        for(int i=0; i<n; i++){
            cin >> arr[i].s;
            arr[i].f=0;
            for(int j=0; j<arr[i].s; j++){
                int temp; cin >> temp;
                arr[i].f = max(arr[i].f, temp-j+1);
            }
            
        }
        sort(arr,arr+n,sf);
        int ans = 1; int tsum = 0;
        for(int i=0; i<n; i++){
            ans = max(ans, arr[i].f-tsum);
            tsum += arr[i].s;
        }
        cout << ans << "\n";
    }
}
