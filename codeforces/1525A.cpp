#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#define f first
#define s second
#pragma GCC optimize ("unroll-loops")
#pragma GCC optimize ("O3")
#pragma GCC target ("sse,sse2,sse3,ssse3,sse4,abm,avx,avx2,fma,mmx,tune=native")
using namespace std;

int gcd(int a, int b){
    if(b==0) return a;
    else return gcd(b, a%b);
}

int main(){
    int t; cin >> t;
    while(t--){
        int k; cin >> k;
        int gc = gcd(100,k);
        cout << 100/gc << "\n";
    }
}