#include <iostream>
#define csout(x) cout << "Case #" << x << ": ";
using namespace std;

int main(){
    int t; cin >> t;
    for(int tc = 1; tc <= t; tc++){
        bool havetrees = false;
        int r,c; cin >> r >> c;
        char arr[r][c];
        for(int i=0; i<r; i++){
            for(int j=0; j<c; j++){
                cin >> arr[i][j];
                havetrees |= arr[i][j]=='^';
            }
        }
        if((r==1 || c==1) && havetrees){
            csout(tc);
            cout << "Impossible\n";
        } else {
            csout(tc);
            cout << "Possible\n";
            for(int i=0; i<r; i++){
                for(int j=0; j<c; j++){
                    cout << (havetrees?"^":".");
                }
                cout << '\n';
            }
        }
    }
}