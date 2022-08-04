#include <iostream>
#include <cstring>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n,q; cin >> n >> q;
    bool taken[51]; memset(taken,0,sizeof(taken));
    int pos[51]; memset(pos,0,sizeof(pos));
    for(int i=1; i<=n; i++){
        short temp; cin >> temp;
        if(taken[temp])continue;
        taken[temp]=true;
        pos[temp]=i;
    }
    for(int i=0; i<q; i++){
        short temp; cin >> temp;
        cout << pos[temp] << " ";
        for(short j=1; j<=50; j++){
            if(pos[j]<pos[temp]){
                pos[j]++;
            }
        }
        pos[temp]=1;
    }
}