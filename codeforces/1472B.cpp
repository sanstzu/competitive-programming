#include <iostream>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cout.tie(0); cin.tie(0);
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        int c1=0,c2=0;
        for(int i=0; i<n; i++){
            int temp; cin >> temp;
            if(temp==1){
                c1++;
            } else {
                c2++;
            }
            
        }
        if(c1%2==1 || (c2%2==1 && c1<2)){
            cout << "NO\n";
        } else {
            cout << "YES\n";
        }
    }
}