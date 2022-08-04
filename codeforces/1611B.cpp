#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cout.tie(0); cin.tie(0);
    int t; cin >> t;
    while(t--){
        int a,b; cin >> a >> b;
        cout << min((a+b)/4, min(a,b)) << "\n";
    }
}