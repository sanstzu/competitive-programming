#include <bits/stdc++.h>
#define INF 1e9
using namespace std;
//bottom-up approach
int solve(int n, int types, int coins[]){
    int table[n+1];
    table[0]=0; //table for the data
    for (int i=1;i<=n;i++){
        int best=INF;
        for (int c=0; c<types;c++){
            if(i-coins[c]>=0){
                best=min(best,table[i-coins[c]]+1);
            }
        }
        table[i]=best;
    }
    /*for (int i=0; i<=n; i++){
        printf("table[%d] = %d\n", i, table[i]);
    }*/
    return table[n];
}

int main(){
    int types;
    scanf("%d", &types);
    int coins[types];
    for(int i=0;i<types;i++){
        scanf("%d", &coins[i]);
    }
    int n;
    scanf("%d", &n);
    int temp=solve(n,types,coins);
    if (temp<1e9){
        printf("%d\n",temp);
    } else {
        printf("-1\n");
    }
}
