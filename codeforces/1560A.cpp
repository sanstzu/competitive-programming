#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t; cin >> t;
    while(t--){
        int k; cin>>k;
        int temp = 1, cur = 1;
        while(temp<k){
            cur++;
            if(cur%10==3 || cur%3==0){
                continue;
            } else {
                temp++;
            }
        }
        cout << cur << "\n";
    }
}