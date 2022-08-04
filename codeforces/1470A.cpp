#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

void solve(){
    int n,m; cin >> n >> m;
    vector<int> k(n), c(m);
    long long ans=0;
    for(int i=0; i<n; i++){
        cin >> k[i];
    }
    for(int i=0; i<m; i++) cin >> c[i];
    sort(k.begin(),k.end(),greater<int>());
    int ptr=0;
    for(int i=0 ;i<n; i++){
        if(c[k[i]-1]<=c[ptr]){
            ans+=c[k[i]-1];
            //cout << "a " << i << " " << ans << "\n";
        } else {
            ans+=c[ptr++];
            //cout << "b " << i << " " << ans << "\n";
        }
    }
    cout << ans << "\n";
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t; cin >> t;
    while(t--){
        solve();
    }
}