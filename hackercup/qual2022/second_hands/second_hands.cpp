#include <iostream>
#include <vector>
using namespace std;

int main(){
    //ios::sync_with_stdio(0);
    //cout.tie(0); cin.tie(0);
    int t; cin >> t;
    int cnt = 0;
    while(cnt<t){
        int n,k; cin >> n >> k;
        vector<int> s(101,0);
        for(int i=0; i<n; i++){
            int temp; cin >> temp;
            s[temp]++;
        }
        int si = 0, d = 0;
        bool failed = false;
        for(int i: s){
            if(i==0) continue;
            else if(i==1) si++;
            else if(i==2) d++;
            else failed = true;
        }
        if(failed || d > k || (2*d + si) > 2*k) cout << "Case #" << cnt+1 << ": " << "NO\n";
        else cout << "Case #" << cnt+1 << ": " << "YES\n";
        cnt++;
    }
}