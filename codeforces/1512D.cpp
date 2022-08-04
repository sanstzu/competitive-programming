#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;
typedef long long ll;
void solve(){
    int n; cin >> n;
    ll sum=0;
    unordered_map<int,int> cnt;
    int b[n+2]; for(int i=0; i<n+2; i++){
        cin >> b[i]; sum+=(long long)b[i];
        cnt[b[i]]++;
    }
    sort(b,b+n+2,greater<int>());
    bool found=false;
    for(int i=0; i<n+2 && !found; i++){
        long long temp1=(sum-((long long)b[i]<<(long long)1));
        if(temp1>(long long)1e9) continue;
        int temp = (int) temp1;
        if(cnt.count(temp)==0)continue;
        if((temp!=b[i]) || (cnt[temp]>1 && temp==b[i])){
            cnt[temp]--;
            cnt[b[i]]--;
            found=true;
            //cout << "found at: " << i << " " << temp << " " << b[i]  << "\n";
        }
    }
    if(!found){
        cout << "-1\n";
        return;
    } else {
        for(pair<int,int> temp:cnt){
            for(int i=0; i<temp.second; i++){
                cout << temp.first << " ";
            }
        }
    } cout << "\n";
}

int main(){
    ios::sync_with_stdio(0);
    cout.tie(0); cin.tie(0);
    int t; cin >> t;
    while(t--){
        solve();
    }
}