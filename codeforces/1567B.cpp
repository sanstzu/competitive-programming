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
const int NUM = 3e5 + 10;
int pref[NUM];
void init(){
    pref[0]=0;
    for(int i=1; i<NUM; i++){
        pref[i] = i^pref[i-1];
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    init();
    int t; cin >> t;
    while(t--){
        int a,b; cin >> a >> b;
        //cout << "p" << pref[a-1]^b << "\n";
        if(pref[a-1]==b){
            cout << a << "\n";
        } else if((pref[a-1]^b)==a){
            cout << a+2 << "\n";
        } else {
            cout << a+1 << "\n";
        }
    }
}

