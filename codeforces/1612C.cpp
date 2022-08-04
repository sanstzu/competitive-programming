#include <iostream>
using namespace std;

void solve(){
    long long k,x; cin >> k >> x;
    x--;
    if(x >= k*(k+1)/2 + k*(k-1)/2){
        //limit larger than msg
        cout << 2*k-1 << "\n";
    } else if(k*(k+1)/2 < x+1){
        //limit larger than half
        x -= (k*(k+1)/2);
        int l=1, r=k-1;
        while(r>l){
            long long mid = (l+r)>>1;
            //cout << "mid: " << mid << "\n";
            if(mid*(2*k - 1 - mid)/2 > x){
                r = mid;
            } else {
                l = mid+1;
            }
        }
        cout << l+k << "\n";
    
    } else {
        //smaller
        int l=1, r=k;
        while(r>l){
            long long mid = (l+r)>>1;
            if(mid*(mid+1)/2 > x){
                r = mid;
            } else {
                l = mid+1;
            }
        }
        cout << l << "\n";
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t; cin >> t;
    while(t--){
        solve();
    }
}