#include <iostream>
#include <map>
#include <algorithm>
using namespace std;

void solve(){
    int n; cin >> n;
    map<int,int> cum;
    for(int i=0; i<n; i++){
        int temp; cin >> temp;
        cum[temp]++;
    }
    map<int,int> setfreq;
    for(pair<int,int> i: cum){
        setfreq[i.second]++;
    }
    int ans=n;
    for(pair<int,int> i:setfreq){
        int tempans=0;
        for(pair<int,int> j: setfreq){
            if(j.first<i.first){
                tempans+=j.first*j.second;
            } else {
                tempans+=(j.first-i.first)*j.second;
            }
        }
        ans=min(ans,tempans);
    }
    cout << ans << "\n";
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t; cin >> t;
    while(t--)solve();
}