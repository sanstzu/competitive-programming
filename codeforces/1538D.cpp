#include <iostream>
#include <cmath>
#include <map>
#include <cstring>
#include <vector>
#include <algorithm>
#include <bitset>
#pragma GCC optimize ("unroll-loops")
#pragma GCC optimize ("O3")
#pragma GCC target ("sse,sse2,sse3,ssse3,sse4,abm,avx,avx2,fma,mmx,tune=native")
using namespace std;

int sopf(int a){
    int temp = a, ul = ceil((double)sqrt((double)a));
    int ans = 0;
    for(int i=2;temp>1 && i<(ul+2);i++){
        while(temp>1 && temp%i==0){
            temp/=i; ans++;
        }
    }
    if(temp>1) ans++;
    return ans;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t; cin >> t;
    while(t--){
        int a,b,k; cin >> a >> b >> k;
        if(a>b){
            int temp = a;
            a = b;
            b = temp;
        }
        int ul = sopf(a) + sopf(b);
        if(k>=(2 - (b%a==0 && b!=a)) && k<=ul) cout << "Yes\n";
        else cout << "No\n";
    }
}