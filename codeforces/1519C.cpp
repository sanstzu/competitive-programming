#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <bitset>
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
        int u[n],s[n];
        for(int i=0; i<n; i++){
            cin >> u[i];
        }
        for(int i=0; i<n; i++){
            cin >> s[i];
        }
        vector<long long> psum[n+1];
        for(int i=0; i<n; i++){
            if(psum[u[i]].size()==0){
                psum[u[i]].push_back(0);
            }
            psum[u[i]].push_back(s[i]);
        }
        for(int i=1; i<=n; i++){
            sort(psum[i].begin(),psum[i].end());
            for(int j=1;j<psum[i].size(); j++){
                psum[i][j]+=psum[i][j-1];
            }
        }
        long long ans[n]; memset(ans,0,sizeof(ans));
        for(int i=1; i<=n; i++){
            int sz = psum[i].size()-1;
            for(int j=1; j<=sz; j++){
                ans[j-1]+=(psum[i][sz]-psum[i][sz%j]);
            }
        }
        for(int i=0; i<n; i++){
            cout << ans[i] << " ";
        } cout << "\n";
    }
}