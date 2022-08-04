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
        int a, b; cin >> a >> b;
        if(a>b){
            int temp = a;
            a = b; b = temp;
        }
        int n = a+b;
        bool poss[n+1]; memset(poss,0,sizeof(poss));
        int cnt = 0;
        
        if(n%2==0){
            for(int i=0; i<=a && (n/2 - a + 2*i)<=n; i++){
                if(!poss[n/2 - a + 2*i]) cnt++;
                poss[n/2 - a + 2*i] = true;
            }
        } else {
            //starts with A serving
            for(int i=0; i<=a && (n/2 + 1 - a + 2*i)<=n; i++){
                if(!poss[n/2 + 1 - a + 2*i]) cnt++;
                poss[n/2 + 1 - a + 2*i] = true;
            }
            //starts with B serving
            for(int i=0; i<=a && (n/2 - a + 2*i)<=n ; i++){
                if(!poss[n/2 - a + 2*i]) cnt++;
                poss[n/2 - a + 2*i] = true;
            }
        }
        cout << cnt << "\n";
        for(int i=0; i<=n ; i++){
            if(poss[i]) cout << i << " ";
        } cout << "\n";
    }
}
