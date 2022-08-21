#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cout.tie(0); cin.tie(0);
    int t; cin >> t;
    while(t--){
        int n,k; cin >> n >> k;
        pair<int,int> arr[n];
        for(int i=0; i<n; i++){
            cin >> arr[i].first;
            arr[i].second = i;
        }
        sort(arr,arr+n);
        int ans = 0;
        for(int i=0; i<k; i++){
            if(arr[i].second >= k) ans++;
        }
        cout << ans << "\n";
    }
}