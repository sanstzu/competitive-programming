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
        int r,b,d; cin >> r >> b >> d;
        int dif = abs(r-b);
        int minn = min(r,b);
        if((dif+minn-1)/minn<=d){
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
}