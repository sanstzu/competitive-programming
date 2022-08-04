#include <iostream>
#include <map>
#include <cstring>
#include <vector>
#include <algorithm>
#pragma GCC optimize ("unroll-loops")
#pragma GCC optimize ("O3")
#pragma GCC target ("sse,sse2,sse3,ssse3,sse4,abm,avx,avx2,fma,mmx,tune=native")
using namespace std;
const int SZ = (1<<19)+69;
int k;
int tree[SZ];
char type[SZ];

void construct(int node){
    if(node>=(1<<k)) return;
    construct(node<<1); construct((node<<1)+1);
    if(type[node]=='0'){
        tree[node] = tree[(node<<1)]; 
    } else if(type[node]=='1'){
        tree[node] = tree[(node<<1)+1]; 
    } else {
        tree[node] = tree[(node<<1)] + tree[(node<<1)+1]; 
    }
}

void update(int node, bool prev){
    if(node==0 || (type[node]!='?' && (type[node]-'0')!=prev)) return;
    if(type[node]=='0'){
        tree[node] = tree[(node<<1)]; 
    } else if(type[node]=='1'){
        tree[node] = tree[(node<<1)+1]; 
    } else {
        tree[node] = tree[(node<<1)] + tree[(node<<1)+1]; 
    }
    update(node>>1,node%2);
}

inline int convert(int x) {
    //converting tree index to question index
    int b = 1;
    while (x >= (1<<b)) b++;
    b--;
    return (1<<k)-3*(1<<b)+x+1;
}

inline int revert(int x) {
    //converting question index to tree index
    int b = 1;
    while((1<<k)-x >= (1<<b)) b++;
    b--;
    return x - (1<<k) + 3*(1<<b) - 1;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> k;
    for(int i=1; i<(1<<k); i++) {
        cin >> type[revert(i)];
    }
    for(int i=(1<<k); i<(1<<(k+1)); i++) tree[i]=1;
    construct(1);
    int q; cin >> q;
    while(q--){
        int node; cin >> node;
        node = revert(node);
        char typ; cin >> typ;
        type[node] = typ;
        if(typ=='0'){
            tree[node] = tree[(node<<1)];
        } else if(typ=='1'){
            tree[node] = tree[(node<<1)+1];
        } else {
            tree[node] = tree[(node<<1)+1]+ tree[(node<<1)];
        }
        update(node>>1,node%2);
        cout << tree[1] << "\n";
    }
}