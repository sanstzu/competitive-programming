#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t; cin >> t;
    while(t--){
        int k; cin >> k;
        int sector = sqrt((long double)k-0.1)+1;
        int midpoint = ((((sector-1)*(sector-1)+1)+(sector*sector))>>1);
        if( k < midpoint ){
            cout << sector - midpoint + k << " " << sector << "\n";
        } else {
            cout << sector << " " << sector - k + midpoint << "\n";
        }
    }
}