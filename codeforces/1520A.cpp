#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
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
        bool finish[30]; memset(finish,0,sizeof(finish));
        bool failed=false;
        char prev;
        for(int i=0; i<n; i++){
            char temp; cin >> temp;
            if(i>0 && prev!=temp){
                if(finish[temp-'A']) failed=true;
                finish[prev-'A']=true;
            }
            prev=temp;
        }
        if(failed) cout << "NO\n";
        else cout << "YES\n";
    }
}