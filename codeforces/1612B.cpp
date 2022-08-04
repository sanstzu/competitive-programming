#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t; cin>>t;
    while(t--){
        int n,a,b; cin >> n >> a >> b;
        bool taken[n+1]; memset(taken,0,sizeof(taken));
        taken[a]=taken[b]=true;
        int cnt=1,itr=n;
        vector<int> ans; ans.push_back(a);
        while(cnt<(n/2) && itr>a){
            if(taken[itr]){
                itr--; continue;
            } else {
                taken[itr]=true;
                ans.push_back(itr--);
                cnt++;
            }
        }
        if(cnt<(n/2)){
            cout << "-1\n"; continue;
        }
        cnt=1; itr=1;
        ans.push_back(b);
        
        while(cnt<(n/2) && itr<b){
            if(taken[itr]){
                itr++; continue;
            } else {
                taken[itr]=true;
                ans.push_back(itr++);
                cnt++;
            }
        }

        if(cnt<(n/2)){
            cout << "-1\n"; continue;
        }

        for(int i:ans){
            cout << i << " ";
        } cout << "\n";
    }
}