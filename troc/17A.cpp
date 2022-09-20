#include <iostream>
using namespace std;

int main(){
    short n; cin >> n;
    bool odd=0;
    while(n--){
        short temp; cin >> temp;
        odd=temp%2-odd;
    }
    cout << odd << "\n";
}