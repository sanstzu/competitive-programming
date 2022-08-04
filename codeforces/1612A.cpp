#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    ios::sync_with_stdio(0);\
    cout.tie(0); cin.tie(0);
    int t; cin >> t;
    while(t--){
        int x,y; cin >> x >> y;
        if((x+y)%2){
            cout << "-1 -1\n";
        } else {
            if(x>y){
                cout << (x-y)/2 << " " << y << "\n";
            } else {
                cout << x << " " << (y-x)/2 << "\n";
            }
        }
    }
}