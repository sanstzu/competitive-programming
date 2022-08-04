#include <iostream>
#include <map>
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
        vector<int> curr;
        for(int i=0; i<n; i++){
            int temp; cin >> temp;
            if(temp==1){
                curr.push_back(1);
            } else {
                while(curr.back()!=temp-1){
                    curr.pop_back();
                }
                curr.back()++;
            }
            cout << curr.front();
            for(int i=1; i<curr.size(); i++){
                cout << '.' << curr[i];
            } cout << "\n";
        }
    }
}