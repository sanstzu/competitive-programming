#include <iostream>
#include <algorithm>
using namespace std;
const int MAX = 1e3+69;
int par[MAX], size[MAX];
void init(){
    for(int i=0; i<MAX; i++) {par[i]=i;size[i]=1;}

}

int fp(int a){
    if(par[a]!=a){
        return par[a]=fp(par[a]);
    } else return a;
}

void merge(int a, int b){
    int ra = fp(a), rb = fp(b);
    par[ra]=rb;
    size[rb]+=size[ra];
}
int main(){
    ios::sync_with_stdio(0);
    cout.tie(0); cin.tie(0);
    init();
    int n,d; cin >> n >> d;
    int max_size = 1;
    for(int i=0; i<d; i++){
        int x,y; cin >> x >> y;
        merge(x,y);
    }
}