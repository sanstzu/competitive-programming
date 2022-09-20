#include <cstdio>
using namespace std;

int main(){
    int a[2],b[2],dist[2],dista;
    scanf("%d %d %d %d", &a[0], &a[1], &b[0], &b[1]);
    for (int x; x<2; x++){
        dist[x]=a[x]-b[x];
        if (dist[x]<0){
            dist[x]=dist[x]*(-1);
        }
    }
    dista=dist[0]+dist[1];
    printf("%d\n",dista);
}