#include <iostream>
#include <map>
#include <cstring>
#include <vector>
#include <algorithm>
#include <deque>
#define f first
#define s second
#pragma GCC optimize ("unroll-loops")
#pragma GCC optimize ("O3")
#pragma GCC target ("sse,sse2,sse3,ssse3,sse4,abm,avx,avx2,fma,mmx,tune=native")
using namespace std;
const int INF = 2e9+69;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t; cin>>t;
    while(t--){
        int n; cin >> n; int arr[n];
        for(int i=0; i<n; i++) cin >> arr[i];
        sort(arr,arr+n);
        int cur = INF, ans = 1;
        for(int i=1; i<n; i++){
            cur = min(abs(arr[i]-arr[i-1]),cur);
            //cout << cur << " ";
            if(cur>=arr[i]) ans = i+1;
        }
        cout << ans << "\n";
    }
}