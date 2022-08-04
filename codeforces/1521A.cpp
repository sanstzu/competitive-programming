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
    cout.tie(0); cin.tie(0);
    int t; cin >> t;
    while(t--){
        long long a,b; cin >> a >> b;
        if(b==1){
            cout << "NO\n";
            continue;
        } else {
            cout << "YES\n";
            b*=2;
            long long x = a*(b-1);
            long long y = a;
            long long z = a*b;
            cout << x << " "<< y << " " << z << "\n";
        }
    }
}