#include <iostream>
#include <string>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cout.tie(0); cin.tie(0);
    int t; cin >> t;
    while(t--){
        string str; cin >> str;
        if((str.back()-'0')%2==0){
            cout << "0\n";
        } else if((str[0]-'0')%2==0){
            cout << "1\n";
        } else {
            bool haveEven = false;
            for(char i: str){
                if((i-'0')%2==0) haveEven=true;
            }
            if(haveEven){
                cout << "2\n";
            } else {
                cout << "-1\n";
            }
        }
    }
}