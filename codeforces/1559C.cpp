#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        int in = -1;
        int prev; cin >> prev;
        if(prev==1) in = 0;
        for(int i=1; i<n; i++){
            int temp; cin >> temp;
            if(in==-1 && prev==0 && temp==1) in = i;
            prev = temp;
        }
        if(in==-1 && prev==0) in = n;
        
        if(in==-1){
            cout << "-1\n";
        } else {
            for(int i=0; i<=n; i++){
                if(i>0)cout << i << " ";
                if(in==i) cout << n+1 << " ";
            } cout << "\n";
        }
    }
}