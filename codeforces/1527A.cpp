#include <iostream>
#include <queue>
#include <cstring>
#include <vector>
#include <algorithm>
#include <deque>
#define f first
#define s second
#pragma GCC optimize ("unroll-loops")
#pragma GCC optimize ("O3")
#pragma GCC target ("sse,sse2,sse3,ssse3,sse4,abm,avx,avx2,fma,mmx,tune=native")
using namespace std;

int main(){
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        int temp =n ; int cnt = 0;
        while(temp>0){
            temp>>=1;
            cnt++;
        }
        cout << (1<<(cnt-1))-1 << "\n";
    }
}