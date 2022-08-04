#include <iostream>
#include <algorithm>
using namespace std;

void solve(){
    int n; cin >> n;
    int r[n];
    for(int i=0; i<n; i++)cin >> r[i];
    int LSS1=0,cursum=0;
    for(int i=0; i<n; i++){
        cursum+=r[i];
        LSS1=max(LSS1,cursum);
    }
    int m; cin >> m;
    int b[m];
    int LSS2=0;
    cursum=0;
    for(int i=0; i<m; i++)cin >> b[i];
    for(int i=0; i<m; i++){
        cursum+=b[i];
        LSS2=max(LSS2,cursum);
    }
    cout << LSS1+LSS2 << "\n";
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t; cin>>t;
    while(t--){
        solve();
    }
}