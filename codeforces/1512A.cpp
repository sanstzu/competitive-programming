#include <iostream>
#include <cstring>
using namespace std;

void solve(){
    int n;  cin >> n;
        int arr[n]; for(int i=0; i<n; i++) cin >> arr[i];
        int count[101]; for(int i=0; i<101; i++)count[i]=0;
        for(int i=0; i<n; i++){
            count[arr[i]]++;
        }
        int single=-1;
        for(int i=1; i<101; i++){
            if(count[i]==1){
                single=i; break;
            }
        }
        for(int i=0; i<n; i++){
            if(arr[i]==single){
                cout << i+1 << "\n";
                return;
            }
        }
}
int main(){
    int t; cin >> t;
    while(t--){
        solve();
    }
}