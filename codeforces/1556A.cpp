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
        int a,b; cin >> a >> b;
        if(abs(a-b)%2==1){
            cout << "-1\n";
        } else if(a!=b){
            cout << "2\n";
        } else if(a>0 && b>0){
            cout << "1\n";
        } else {
            cout << "0\n";
        }
    }
}

