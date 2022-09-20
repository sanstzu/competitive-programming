#include <cstdio>
using namespace std;
#define INF 1001
short V,E,src,b;
short jarak[2500][2500]={INF};
short dist[2500];
bool visited[2500] = {0};
short parent[100];

void init(){
    for (int i = 0; i<V; i++){
        dist[i] = INF;
        parent[i] = i;
    }
    
}

int getNearest(){
    int minvalue = INF;
    int minnode = 0;
    for(int i = 0 ; i < V ; i++){
        if( !visited[i] && dist[i] < minvalue){
            minvalue = dist[i];
            minnode = i;
        }
    }
    return minnode;
}

void dijkstra(){
    for(int i=0; i<V;i++){
        int nearest = getNearest();
        visited[nearest] = true;

        for(int adj = 0 ; adj<V ; adj++){
            if(jarak[nearest][adj] != INF && dist[adj]>dist[nearest]+jarak[nearest][adj] && !visited[b])
                dist[adj] =  dist[nearest]+jarak[nearest][adj];
                parent[adj] = nearest;
        }
    }
}

int main(){
    scanf("%i %i %i %i",&V, &E, &src, &b);
    for (int i=0;i<E;i++){
        int tempA,tempB,tempC;
        scanf("%i %i %i", &tempA, &tempB, &tempC);
        jarak[tempA][tempB]=tempC;
        jarak[tempB][tempA]=tempC;
    }
    init();
    dijkstra();
    printf("%i", dist[b]);
}