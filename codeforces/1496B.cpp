#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t; cin>>t;
    while(t--){
        int n,k; cin >> n >> k;
        vector<int> picked(n);
        map<int,bool> taken;
        int mex=0;
        for(int i=0; i<n; i++){
            cin >> picked[i];
            taken[picked[i]]=true;
        }
        sort(picked.begin(),picked.end());
        
        //cout << "mex: " << mex << "\n";
        if(picked[0]==0 && picked[n-1] == n-1){
            cout << n+k << "\n";
        } else {
            for(int i=0; i<n && mex>=picked[i]; i++){
                if(mex==picked[i])mex++;
            }
            if(taken.count((mex+picked[n-1]+1)>>1) || k==0){
                cout << n << "\n";
            } else {
                cout << n+1 << "\n";
            }
        }
    }
}