#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
    int n; cin >> n;
    int ans=0,curr=0;
    vector<int> exists(200001,-2);
    exists[100000]=-1;
    for(int i=0; i<n; i++){
        char temp; cin >> temp;
        curr +=(temp-'0')*2-1;
        if(exists[curr+100000]!=-2){
            ans=max(ans,i-exists[curr+100000]);
        } else {
            exists[curr+100000]=i;
        }
    }
    cout << ans << "\n";
}