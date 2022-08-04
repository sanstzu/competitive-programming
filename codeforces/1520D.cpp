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
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        map<int,int> cnt;
        for(int i=0; i<n; i++){
            int temp; cin >> temp;
            cnt[i-temp]++;
        }
        long long ans = 0;
        
        for(pair<int,int> tmp: cnt){
            if(tmp.second<2) continue;
            ans += ((long long)tmp.second*((long long)tmp.second-1))/2;
        }
        cout << ans << "\n";
    }
}