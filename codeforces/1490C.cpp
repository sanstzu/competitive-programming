#include <iostream>
#include <cmath>
using namespace std;
typedef long long ll;

inline long long cube(int num){
    return ((long long)num*num)*num;
} 

bool solve(long long x){
    for(int i=1; cube(i)<=x; i++){
        int j=max((int)cbrt(x-cube(i))-1,1);
        for(; cube(j)+cube(i)<=x; j++){
            if(cube(j)+cube(i)==x){
                return true;
            }
        }
    }
    return false;
}

int main(){
    int t; cin >> t;
    while(t--){
        ll x; cin >> x;
        if(solve(x)){
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
}