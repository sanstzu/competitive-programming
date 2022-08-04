#include <iostream>
#include <string>
using namespace std;

int main(){
    int t; cin >> t;
    while(t--){
        string str; cin >> str;
        int len= str.length();
        int posO,posC;
        for(int i=0; i<len; i++){
            if(str[i]=='(')posO=i;
            if(str[i]==')')posC=i;
        }
        if(len%2==1 || posC==0 || posO==len-1){
            cout << "NO\n";
        } else {
            cout << "YES\n";
        }
    }
}