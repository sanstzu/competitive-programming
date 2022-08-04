#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cout.tie(0); cin.tie(0);
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        long long arr[n]; long long tfac=0;
        for(int i=0; i<n; i++){
            cin >> arr[i];
            while(arr[i]%2==0){
                arr[i]>>=1;
                tfac++;
            }
        }
        sort(arr,arr+n);
        arr[n-1]<<=tfac;
        long long ans = 0;
        for(int i=0; i<n; i++)ans+=arr[i];
        cout << ans << "\n";
    }
}