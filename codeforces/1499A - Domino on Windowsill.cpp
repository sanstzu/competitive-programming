#include <iostream>
#include <cmath>
using namespace std;

void solve(){
    int n,k1,k2; cin >> n >> k1 >> k2;
    int w,b; cin >> w >> b;
    //checking if its possible to place white
    if(((k1+k2)>>1)>=w && ((2*n-k1-k2)>>1)>=b){
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
}

int main(){
    int t; cin >> t;
    while(t--)solve();
}