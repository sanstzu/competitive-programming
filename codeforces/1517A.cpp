#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <cmath>
#pragma GCC optimize ("unroll-loops")
#pragma GCC optimize ("O3")
#pragma GCC target ("sse,sse2,sse3,ssse3,sse4,abm,avx,avx2,fma,mmx,tune=native")
using namespace std;

int main(){
    int t; cin >> t;
    while(t--){
        long long n; cin >> n;
        if(n%2050){
            cout << "-1\n";
            continue;
        } else {
            long long div=(long long)2e17+(long long)5e15;
            int cnt = 0;
            while(n>0 && div>=2050){
                while(n>=div){
                    cnt++;
                    n-=div;
                }
                div/=10;
            }
            cout << cnt << "\n";
        }
    }
}