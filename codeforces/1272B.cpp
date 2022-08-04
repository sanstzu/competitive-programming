#include <bits/stdc++.h>
using namespace std;

void solve(){
    string temp; cin >> temp;
    int len=temp.length();
    int L=0,R=0,U=0,D=0;
    for(int i=0; i<len; i++){
        switch(temp[i]){
            case 'L':
                L++; break;
            case 'R':
                R++; break;
            case 'U':
                U++; break;
            case 'D':
                D++; break;
        }
    }
    int minY=min(U,D),minX=min(L,R);
    if(minY==0 && minX==0){
        cout << "0\n";
    } else if(minY==0){
        cout << "2\nLR\n";
    } else if(minX==0){
        cout << "2\nUD\n";
    } else {
        cout << (minY+minX)*2 << "\n";
        for(int i=0; i<minY; i++)cout<<"U";
        for(int i=0; i<minX; i++) cout<<"R";
        for(int i=0; i<minY; i++)cout<<"D";
        for(int i=0; i<minX;i++)cout<<"L";
        cout<< "\n";
    }
}

int main(){
    int q; cin >> q;
    while(q--){
        solve();
    }
}