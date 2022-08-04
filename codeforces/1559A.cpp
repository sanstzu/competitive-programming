#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        int ans=(1<<30)-1;
        for(int i=0; i<n; i++){
            int temp; cin >> temp;
            ans&=temp;
        }
        cout << ans << "\n";
    }
}