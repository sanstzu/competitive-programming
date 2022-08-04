#include <iostream>
#include <map>
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
    int t; cin>>t;
    while(t--){
        int n; cin >> n;
        map<int,int> arr;
        for(int i=0; i<n; i++){
            int temp; cin >> temp;
            arr[temp]++;
        }
        for(auto i: arr){
            cout << n-i.s << "\n";
            break;
        }
    }
}