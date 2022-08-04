#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cout.tie(0); cin.tie(0);
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        int arr[n]; for(int i=0; i<n; i++){
            cin >> arr[i];
        }
        if(arr[0]==n){
            cout << n << " ";
            for(int i=n-1; i>0; i--) cout << arr[i] << " ";
            cout << "\n";
        } else if(arr[n-1]==n){
            cout << n << " ";
            for(int i=n-2; i>=0; i--) cout << arr[i] << " ";
            cout << "\n";
        } else {
            cout << "-1\n";
        }
    }
}