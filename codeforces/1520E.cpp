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
typedef pair<int,int> pii;
int main(){
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vector<int> arr;
        for(int i=0; i<n; i++){
            char temp; cin >> temp;
            if(temp=='*') arr.push_back(i);
        }
        int m = (arr.size())>>1;
        long long ans = 0;
        for(int i=0; i<arr.size(); i++){
            ans+= abs(arr[i] - (arr[m] - m + i));
        }
        cout << ans << "\n";
    }
}