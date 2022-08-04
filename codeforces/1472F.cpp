#include <iostream>
#include <map>
#define f first
#define s second
using namespace std;

void solve(){
    int n,m; cin >> n >> m;
    map<int,int> bm; //YX = X first row, Y sec row
    for(int i=0; i<m; i++){
        int r,c; cin >> r >> c;
        bm[c]|=1<<(r-1);
    }
    int curbm=0;
    int prevcol;
    for(pair<int,int> tmp:bm){
        //same row -> col2-col1 % 2 == 1
        //diff row -> col2-col1 % 2 == 0
        if(curbm==0){
            curbm=tmp.s%3;
            prevcol=tmp.f;
            continue;
        }
        if((tmp.s==1 && curbm==1) || (tmp.s==2 && curbm==2)){
            if((tmp.f-prevcol)%2==1){
                curbm=0; prevcol=tmp.f;
            } else {
                cout << "NO\n";
                return;
            }
        } else if((tmp.s==1 && curbm==2) || (tmp.s==2 && curbm==1)){
            if((tmp.f-prevcol)%2==0){
                curbm=0; prevcol=tmp.f;
            } else {
                cout << "NO\n";
                return;
            }
        } else {
            cout << "NO\n";
            return;
        }
    }
    if(curbm==0){
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
}

int main(){
    int t; cin >> t;
    while(t--) solve();
}