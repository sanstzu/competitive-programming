#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <map>
#pragma GCC optimize ("unroll-loops")
#pragma GCC optimize ("O3")
#pragma GCC target ("sse,sse2,sse3,ssse3,sse4,abm,avx,avx2,fma,mmx,tune=native")
using namespace std;

int main(){
    int n,t,k; cin >> n >> t >> k;
    int l=0, r=n-1;
    int temp;
    while(l<r){
        int mid =(l+r)>>1;
        cout << "? 1 " << mid+1 << endl;
        int inpt; cin >> inpt;
        temp = mid+1-inpt;
        if(temp<k){
            l=mid+1;
        } else {
            r = mid;
        }
    }
    cout << "! " << l+1 << endl;
}
// 1 0 1 0 1 1 1 0 1 1
// n = 