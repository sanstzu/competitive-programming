#include <bits/stdc++.h>
using namespace std;
const int MOD=1e9+7;

inline mul(int x, int y){
    return ((long long)x*y)%MOD;
}

int fp(int a, int b){
    if(b==0) return 1;
    if(b%2){
        return mul(a,fp(a,b-1));
    } else {
        int res = fp(a,(b>>1));
        return mul(res,res);
    }
}

void solve(){
    int n,k; cin >> n >> k;
    cout << fp(n,k) << "\n";
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t; cin >> t;
    while(t--){
        solve();
    }
}