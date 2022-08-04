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
vector<char> powers[63];
void init(){
    powers[0].push_back('1');
    long long cur = 1;
    for(int i=1; i<63; i++){
        cur<<=1;
        string temp = to_string(cur);
        for(char j: temp){
            powers[i].push_back(j);
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    init();
    int t; cin >> t;
    while(t--){
        int k; cin >> k;
        string cur = to_string(k);
        int len = cur.length();
        int itrpow, itrcur;
        int ans = 1e9;
        for(int i=0; i<63; i++){
            itrpow=0, itrcur=0;
            int plen=powers[i].size();
            //cout << "3 " << i << "\n";;
            while(itrcur<len && itrpow<plen){
                //cout << itrcur  << " " << itrpow << "\n";
                if(cur[itrcur]==powers[i][itrpow])itrpow++;
                itrcur++;
            }
            ans = min(ans, len - itrpow + plen - itrpow);
            //cout << i << " - " << ans << " " << itrpow << " " << itrcur << "\n";
        }
        cout << ans << "\n";
    }
}