#include <iostream>
using namespace std;

int main(){
    int t; cin >> t;
    while(t--){
        int w,h,n; cin >> w >> h >> n;
        int countl=1,counth=1;
        while(w%2==0){
            countl<<=1;
            w>>=1;
        }
        while(h%2==0){
            counth<<=1;
            h>>=1;
        }
        if(((long long)counth*countl)>=n){
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
}