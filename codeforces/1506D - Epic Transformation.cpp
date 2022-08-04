#include <iostream>
#include <map>
#include <algorithm>
using namespace std;

void solve(){
    int n; cin >> n;
    map<int,int> freq;
    for(int i=0; i<n; i++){
        int temp; cin >> temp;
        freq[temp]++;
    }
    int sfreq[(int)freq.size()];
    int temp=0;
    for(pair<int,int> tempp: freq){
        sfreq[temp++]=tempp.second;
    }
    int mx=-1;
    for(int i=0; i<freq.size(); i++){
        mx=max(mx,sfreq[i]);
    }
    /*
    for(int i=0; i<freq.size(); i++){
        cout << sfreq[i] << " ";
    } cout << "\n";
    */
    if(mx>(n>>1)){
        cout << 2*mx-n << "\n";
    } else {
        cout << n%2 << "\n";
    }
    /*
    /*
    int i=0,j=freq.size()-1;
    int ans =0;
    while(i<j){ 
        if(sfreq[i]>sfreq[j]){
            sfreq[i]-=sfreq[j];
            ans+=sfreq[j]; j--;
        } else if(sfreq[i]<sfreq[j]){
            sfreq[j]-=sfreq[i];
            ans+=sfreq[i]; i++;
        } else {
            ans+=sfreq[i];i++;j--;
        }
    }
    */
   /*
   if(freq.size()>1){
        cout << sfreq[freq.size()-1]-sfreq[freq.size()-2] << "\n";
   } else {
       cout << sfreq[0] << "\n";;
   }
   */
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t; cin >> t;
    while(t--) solve();
}