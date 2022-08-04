#include <iostream>
using namespace std;

int main(){
    string str; cin>> str;
    int len = str.length();
    int cost = 0;
    for(int i=0; i<len-3; i++){
        for(int j=i+2; j<len-1; j++){
            if (str[i]==str[j] && str[i+1]==str[j+1]){
                cost++;
            }
        }
    }
    cout << cost << "\n";
}