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
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        int cnt = 0;
        int hcnt = 0;
        bool arr[n]; 
        for(int i=0; i<(n>>1); i++) {char temp; cin  >> temp; arr[i]=temp-'0'; cnt+=arr[i]; hcnt+=!arr[i];}
        for(int i=(n>>1); i<n; i++) {char temp; cin  >> temp; arr[i]=temp-'0'; cnt+=arr[i];}
        //cout << cnt << "\n";
        if(cnt==n) cout << "DRAW\n";
        else if(hcnt>0 && n%2 && !arr[n>>1]){
            cout << "ALICE\n";
        } else {
            cout << "BOB\n";
        }
    }
}