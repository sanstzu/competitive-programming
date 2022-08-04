#include <iostream>
#include <queue>
#include <cstring>
#include <vector>
#include <algorithm>
#include <map>
#define f first
#define s second
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
        int arr[n]; for(int i=0; i<n; i++) cin >> arr[i];
        map<int,long long> cnt;
        long long ans = 0;
        for(int i=0; i<n; i++){
            ans += (long long)(n-i)*cnt[arr[i]];
            cnt[arr[i]]= cnt[arr[i]]+((long long)i+1);
        }
        cout << ans << "\n";
    }
}