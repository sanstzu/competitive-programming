#include <iostream>
using namespace std;

void solve(){
    long long n,m,x; cin >> n >> m >> x;
    x--;
    long long row = x/n, col= x%n;
    cout << col*m+row+1 << "\n";
}

int main(){
    int t; cin >> t;
    while(t--){
        solve();
    }
}