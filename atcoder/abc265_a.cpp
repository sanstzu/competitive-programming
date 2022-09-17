#include <iostream>
using namespace std;

int main(){
    int x,y,n; cin >> x >> y >> n;
    int ans = 0;
    if(3*x > y){
        ans = y*(n/3) + x*(n%3);
    } else {
        ans = x*(n);
    }
    cout << ans << "\n";
}