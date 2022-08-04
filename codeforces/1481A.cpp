#include <iostream>
#include <string>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t; cin >> t;
    while(t--){
        int x,y; cin >> x >> y;
        string str; cin >> str;
        int x1=0,x2=0,y1=0,y2=0;
        for(int i=0; i<str.length(); i++){
            switch(str[i]){
                case 'U':
                    y2++;
                    break;
                case 'D':
                    y1--;
                    break;
                case 'L':
                    x1--;
                    break;
                case 'R':
                    x2++;
                    break;
            }
        }
        if(x1<=x && x<=x2 && y1<=y && y<=y2){
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
}