#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cout.tie(0); cin.tie(0);
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        int arr[n];
        for(int i=0; i<n; i++) cin >> arr[i];
        int ans=0;
        for(int i=0; i<n-1; i++){
            int up=max(arr[i],arr[i+1]);
            int down = min(arr[i],arr[i+1]);
            while(down*2<up){
                down*=2; ans++;
            }
        }
        cout << ans << "\n";
    }
}