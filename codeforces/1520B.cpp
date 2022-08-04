#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#pragma GCC optimize ("unroll-loops")
#pragma GCC optimize ("O3")
#pragma GCC target ("sse,sse2,sse3,ssse3,sse4,abm,avx,avx2,fma,mmx,tune=native")
using namespace std;

int dgcnt(int x){
    int ans = 0;
    while(x>0){
        x/=10; ans++;
    }
    return ans;
}

int largest_digit(int x){
    while(x>=10){
        x/=10;
    }
    return x;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        int digits=dgcnt(n);
        int ldigit=largest_digit(n);
        int ans = (digits-1)*9;
        int mnd = ldigit;
        for(int i=0; i<digits-1; i++){
            mnd*=10; mnd+=ldigit;
        }
        if(n>=mnd){
            ans+=ldigit;
        } else {
            ans+=(ldigit-1);
        }
        cout << ans << "\n";
    }
}