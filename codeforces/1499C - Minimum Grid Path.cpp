#include <iostream>
#include <algorithm>
using namespace std;
const long long INF=2e18;
void solve(){
    long long n; cin >> n;
    long long odd[(n>>1)+n%2],even[(n>>1)];
    for(int i=1; i<=n; i++){
        if(i%2==0){
            cin >> even[(int)(i>>1)-1];
        } else {
            cin >> odd[(int)(i>>1)];
        }
    }
    /*
    for(int i=0; i<((n>>1)+n%2); i++){
        cout << odd[i] << " ";
    }
    for(int i=0; i<((n>>1)); i++){
        cout << even[i] << " ";
    } cout << "\n";
    */
    long long osum=odd[0], esum=0;
    long long omin=odd[0], emin=INF;
    long long ans=INF;
    for(int total=2; total<=n; total++){
        if(total%2==0){
            esum+=even[(total>>1)-1];
            emin=min(emin, even[(total>>1)-1]);
        } else {
            osum+=odd[(total>>1)];
            omin=min(omin, odd[(total>>1)]);
        }
        ans=min(ans,emin*(n-(total>>1))+omin*(n-(total>>1)-total%2)+osum+esum);
    }
    cout << ans << "\n";
}

int main(){
    int t; cin >> t;
    while(t--)solve();
}