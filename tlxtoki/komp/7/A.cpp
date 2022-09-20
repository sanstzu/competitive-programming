#include <bits/stdc++.h>
#define INF 1e9
using namespace std;

vector<int> coins;
vector<bool> done;
vector<int> table;

int solve(int n){
    printf("d\n");
    if (n<0) return INF;
    if (n==0) return 0;
    if (done[n]) return table[n];
    int best = INF;
    for (int c: coins){
        printf("c: %d\n", c);
        best = min(best,solve(n-c)+1);
    }
    printf("best: %d\n", best);
    done[n]=true;
    table[n]=best;
    return best;
}

int main(){
    int types;
    scanf("%d",&types);
    int temp;
    for (int i=0; i<types ; i++){
        scanf("%d", &temp);
        coins.push_back(temp);
    }
    int n;
    scanf("%d",&n);
    for (int i=0; i<=n; i++){
        done.push_back(false);
    }
    int temp2;
    temp2 = solve(n);
    if (temp < 1e9){
        printf("%d",temp2);
    } else {
        printf("-1");
    }
}