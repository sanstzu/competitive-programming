#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t; cin >> t;
    while(t--){
        long long a,b,c; cin >> a >> b >> c;
        a--;b--;c--;
        if(a>b){
            long long temp=a;
            a=b;
            b=temp;
        }
        long long diff = b-a;
        if((b+diff)%max(b+1,(2*diff))==a && c<(2*diff)){
            cout << (c+diff)%(2*diff)+1 << "\n";
        } else {
            cout << "-1\n";
        }
    }
}