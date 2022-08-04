#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t; cin >> t;
    while(t--){
        int n,k; cin >> n >> k;
        if(k>(n-1)/2){
            cout << "-1\n";
            continue;
        } else {
            bool taken[n+1]; memset(taken,0,sizeof(taken));
            vector<int> seq;
            for(int i=1; i<=k; i++){
                seq.push_back(i);seq.push_back(n+1-i);
            }
            for(int i=k+1; i<(n+1-k); i++){
                seq.push_back(i);
            }
            for(int i: seq){
                cout << i << " ";
            } cout << "\n";
        }
    }
}