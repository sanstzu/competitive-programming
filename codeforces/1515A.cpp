#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <deque>

#pragma GCC optimize ("unroll-loops")
#pragma GCC optimize ("O3")
#pragma GCC target ("sse,sse2,sse3,ssse3,sse4,abm,avx,avx2,fma,mmx,tune=native")
using namespace std;

int main(){
    int t; cin >> t;
    while(t--){
        int n,x; cin >> n >> x;
        int sum=0;
        int arr[n]; for(int i=0; i<n; i++) cin >> arr[i];
        for(int i=0; i<n; i++) sum=sum+arr[i];
        if(sum==x){
            cout << "NO\n";
        } else {
            cout << "YES\n";
            int cursum=0;
            bool taken[n]; memset(taken,0,sizeof(taken));
            int ptr=0;
            for(int i=0; i<n; i++){
                while(taken[ptr] || (cursum+arr[ptr])==x){
                    ptr=(ptr+1)%n;
                }
                cout << arr[ptr] << " ";
                cursum+=arr[ptr];
                taken[ptr]=true;
                ptr=(ptr+1)%n;
            } cout << "\n";
        }

    }
}