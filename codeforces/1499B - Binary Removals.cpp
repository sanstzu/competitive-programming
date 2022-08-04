#include <iostream>
#include <cstring>
#include <string>
using namespace std;
const int INF=2e9;

void solve(){
    string str; cin >> str;
    int sz=str.length();
    bool dp[sz+1]; //dp[i] = is it possible to make a sorted array from the first i char
    dp[0]=dp[1]=dp[2]=true;
    for(int i=3; i<=sz; i++){
        if(str[i-1]<str[i-2]){
            dp[i]=(dp[i-2]&&(str[i-1]>=str[i-3]));//||(i>3&&dp[i-3]&&(str[i-1]>=str[i-4])&&(str[i-2]>=str[i-4]));
            //cout << (dp[i-2]&&(str[i-1]>=str[i-3])) << " " << (dp[i-3]&&(str[i-1]>=str[i-4])&&(str[i-2]>=str[i-4])) << "\n";
        } else {
            dp[i]=dp[i-1]||(dp[i-2]&&(str[i-1]>=str[i-3]));
        }
    }
    if(dp[sz] || dp[sz-1]){
        cout << "YES\n";
    } else {
        cout<< "NO\n";
    }
}

int main(){
    int t; cin >> t;
    while(t--) solve();
}