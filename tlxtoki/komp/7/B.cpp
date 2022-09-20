#include <cstdio>
using namespace std;

bool max(int a, int b){
    if (a>b){
        return true;
    } else {
        return false;
    }
}

int main(){
    int N, K;
    scanf("%d %d", &N, &K);
    int wt[K+1],val[K+1];
    int mem[N+1][K+1][K+1];
    for (int i=1;i<K+1;i++){
        scanf("%d %d", &wt[i], &val[i]);
    }
}