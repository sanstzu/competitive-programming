#include <iostream>
using namespace std;

int main(){
    int n; cin >>n;
    bool found=false;
    bool isLeap=((n%4==0 && n%100!=0)||n%400==0);
    int cday=0;
    while(!found){
        if((n%4==0 && n%100!=0)||n%400==0){
            cday+=2;
            cday%=7;
        } else {
            cday++;
            cday%=7;
        }
        n++;
        if(cday==0 && ((n%4==0 && n%100!=0)||n%400==0)==isLeap){
            found=true;
        }
        
    }
    cout << n << "\n";
}