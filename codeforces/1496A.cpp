#include <iostream>
#include <string>
using namespace std;

int main(){
    int t; cin >> t;
    while(t--){
        int n,m; cin >> n >> m;
        string str; cin >> str;
        bool succ=true;
        if(2*m>=n) succ=false;
        for(int i=0; i<m && succ; i++){
            if(str[i]!=str[n-1-i]) succ=false;
        }
        if(succ){
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
}