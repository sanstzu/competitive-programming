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

int main(){
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        int maxi=-1;
        for(int i=1; i<n && maxi==-1; i+=2){
            cout << "? 1 "<< i << ' ' << i+1 << ' ' << n-1 << endl;
            int r; cin >> r; if(r==-1) return 0;
            
            if(r==n){
                maxi = i+1;
            } else if(r==n-1){
                cout << "? 1 " << i+1 << ' ' << i << ' ' << n-1 << endl;
                cin >> r; if(r==-1) return 0;
                if(r==n) maxi = i;
            }
        }
        if(n%2 && maxi ==-1) maxi = n;
        int ans[n+1];
        for(int i=1; i<=n; i++){
            if(i==maxi) {ans[i]=n; continue;}
            cout <<"? 2 " << i << ' ' << maxi << ' ' << 1 << endl;
            int r; cin >> r; if(r==-1) return 0;
            ans[i]=r;
        }
        cout << "! ";
        for(int i=1; i<=n; i++){
            cout << ans[i] << " ";
        } cout << endl;
    }
}