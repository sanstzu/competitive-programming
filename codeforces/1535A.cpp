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
        vector<pair<int,int>> arr;
        for(int i=0; i<4; i++){
            int temp; cin >> temp;
            pair<int,int> t; t.first = temp; t.second = i;
            arr.push_back(t);
        }
        sort(arr.begin(),arr.end(),greater<pair<int,int>>());
        if(arr[0].second/2 != arr[1].second/2){
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
}