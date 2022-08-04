#include <iostream>
using namespace std;

void solve(){
    int n,k; cin >> n >> k;
        int h[n];
        for(int i=0; i<n; i++) cin >> h[i];
        for(int i=0; i<k-1; i++){
            int ptr=0;
            while(ptr<n && h[ptr]>=h[ptr+1]){
                ptr++;
            }
            if(ptr<n-1){
                h[ptr]++;
            } else {
                cout << "-1\n";
                return;
            }
        }
        int ans=0;
        while(ans<n && h[ans]>=h[ans+1])ans++;
        if(ans<n-1) cout << ans+1  << "\n";
        else cout << "-1\n";
        
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t; cin >> t;
    while(t--)solve();
}