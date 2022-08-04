#include <iostream>
#include <vector>
using namespace std;

long long gcd(long long a, long long b){
    if(a==0) return b;
    return gcd(b%a, a);
}

void solve(){
    long long n; cin >> n;
        for(long long i=n;;i++){
            long long dsum=0;
            long long temp = i;
            while(temp>0){
                dsum+=temp%10;
                temp/=10;
            }
            long long ans= gcd(dsum,i);
            if(ans>1){
                cout << i << '\n';
                return;
            }
        }
}

int main(){
    int t; cin >> t;
    while(t--){
        solve();
    }
}