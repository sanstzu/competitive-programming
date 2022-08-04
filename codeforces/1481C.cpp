#include <iostream>
#include <vector>
using namespace std;

void solve(){
    int n,m; cin >>n>>m;
    int a[n];
    vector<int> diff[n+1],same[n+1];
    int dc=0;
    //cout << 1;
    for(int i=0; i<n; i++) cin >> a[i];
    for(int i=0; i<n; i++){
        int temp; cin >> temp;
        if(a[i]!=temp){
            diff[temp].push_back(i);
            dc++;
        } else {
            same[temp].push_back(i);
        }
    }
    //cout << 2;
    int c[m];
    int ans[m];
    for(int i=0; i<m; i++) cin >> c[i];
    int prev=-1;
    //cout << 3;
    for(int i=m-1; i>=0; i--){
        if(diff[c[i]].size()>0){
            ans[i]=diff[c[i]].back()+1;
            diff[c[i]].pop_back(); dc--;
            prev=ans[i];
        } else {
            if(prev==-1 && same[c[i]].size()==0){
                cout << "NO\n";
                return;
            }
            if(prev==-1){
                ans[i]=same[c[i]].back()+1;
                prev=ans[i];
            } else {
                ans[i]=prev;
            }
        }
    }
    if(dc==0){
        cout << "YES\n";
        for(int i=0; i<m; i++) cout << ans[i] << " ";
        cout << "\n";
    } else {
        cout << "NO\n";
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t; cin >>t;
    while(t--) solve();
}