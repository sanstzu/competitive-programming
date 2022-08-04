#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        bool failed = false;
        for(int i=0; i<n; i++){
            int temp; cin >> temp;
            if(temp<0) failed = true;
        }
        if(failed){
            cout << "NO\n";
        } else {
            cout << "Yes\n";
            cout << 101 << "\n";
            for(int i=0; i<=100; i++) cout << i << " ";
            cout << "\n";
        }
    }

}