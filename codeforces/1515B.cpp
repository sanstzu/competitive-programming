#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <cmath>

#pragma GCC optimize ("unroll-loops")
#pragma GCC optimize ("O3")
#pragma GCC target ("sse,sse2,sse3,ssse3,sse4,abm,avx,avx2,fma,mmx,tune=native")
using namespace std;

int main(){
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        int temp=n; while(temp%2==0){temp>>=1;}
        int sq=sqrt(temp);
        if(n%2==0 && sq*sq==(temp)){
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
}