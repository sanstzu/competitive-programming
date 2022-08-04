#include <iostream>
#include <cstring>
using namespace std;

int fp(int a, int b){
    if(b==0) return 1;
    if(b%2){
        return a*fp(a,b-1);
    } else {
        int ans = fp(a,b/2);
        return ans * ans;
    }
}

int main(){
    int t; cin >> t;
    while(t--){
        int a,b,c; cin >> a >> b >> c;
        int nc = fp(10,c-1);
        int nb, na=nb=nc;
        int mina=fp(10,a-1),minb=fp(10,b-1);
        while(na<mina){
            na*=2;
        }
        while(nb<minb){
            nb*=3;
        }
        cout << na << " " << nb << "\n";
    }
}