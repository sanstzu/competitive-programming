#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cout.tie(0); cin.tie(0);
    int t; cin >> t;
    while(t--){
        int n,l,r,k; cin >> n >>  l >> r >> k;
        int arr[n];
        for(int i=0; i<n; i++)cin >> arr[i];
        sort(arr,arr+n);
        int ans = 0, total = 0, ptr = 0;
        while(arr[ptr]<l)ptr++;
        while(ptr<n && total+arr[ptr]<=k && arr[ptr]<=r){
            total+=arr[ptr];
            ans++;
            ptr++;
        }
        cout << ans << "\n";
    }
}