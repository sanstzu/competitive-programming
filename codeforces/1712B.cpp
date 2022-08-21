#include <iostream>
using namespace std;

int main(){
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        if(n%2==1){
            cout << 1 << " ";
            for(int i=2; i<=n; i+=2){
                cout << i+1 << " " << i << " ";
            }
        } else {
            for(int i=1; i<=n; i+=2){
                cout << i+1 << " " << i << " ";
            }
        }
        cout << "\n";
    }
}