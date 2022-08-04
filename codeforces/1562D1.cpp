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
        int n,q; cin >> n >> q;
        int pref[n+1]; pref[0] = 0;
        int ipref[n+1]; ipref[0] = 0;
        for(int i=1; i<=n; i++){
            char temp; cin >> temp;
            if(temp=='+'){
                pref[i] = pref[i-1] + ( (((i+1)%2)*(-2)) + 1 );
            } else {
                pref[i] = pref[i-1] - ( (((i+1)%2)*(-2)) + 1 );
            }
        }
        for(int i=0; i<q; i++){
            int l,r; cin >> l >> r;
            int sum = pref[r]-pref[l-1];
            if(sum==0){
                cout << 0 << "\n";
            } else {
                cout << (sum%2==0?2:1) << "\n";
            }
        }
    }
}

