#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
const int INF = 1000;
void solve(){
    int n,k; cin >> n >> k;
    string str; cin >> str;
    int dp[55]; for(int i=0; i<55; i++)dp[i]=INF;
    bool first=true; int last=0;
    for(int i=0; i<n; i++){
        if(str[i]=='.')continue;
        last=i;
        if(first){dp[i]=1;first=false;continue;}
        for(int j=i-1; j>=i-k && j>=0; j--){
            if(str[j]=='.')continue;
            dp[i]=min(dp[i],dp[j]+1);
        }
    }
    /*
    for(int i=0; i<n; i++){
        cout << dp[i] << " ";
    } cout << '\n';
    */
    cout << dp[last] << "\n";
}

int main(){
    int t; cin >> t;
    while(t--) solve();
}