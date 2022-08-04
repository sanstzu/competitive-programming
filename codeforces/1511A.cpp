#include <iostream>
#include <cstring>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        int ans=0;
        int arr[n]; for(int i=0; i<n; i++){cin >> arr[i]; if(arr[i]!=2)ans++;}
        cout << ans << "\n";
    }
}