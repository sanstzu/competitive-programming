#include <iostream>
#include <vector>
#include <string>
using namespace std;


int main(){
    int t; cin >> t;
    while(t--){
        string str; cin >> str;
        bool allA=true;
        for(int i=0; i<str.length(); i++){
            if(str[i]!='a')allA=false;
        }
        if(allA){
            cout << "NO\n";
            continue;
        } else {
            cout << "YES\n";
            string temp=str;
            string add="a";
            for(int i=str.length()-1; i>=0; i--){
                if(str[i]!='a'){
                    temp.insert(str.length()-1-i,add);
                    cout << temp << "\n";
                    break;
                }
            }
        }
    }
}