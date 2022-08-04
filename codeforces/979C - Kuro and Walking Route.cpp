#include <iostream>
#include <cstring>
#include <vector>
using namespace std;
vector<int> adj[300000];
long long subX=0,subY=0,x,y;
bool checked[300000];

void dfsX(int node, bool isX){
    checked[node]=true;
    if(node==x)isX=true;
    if(isX)subX++;
    for(int i: adj[node]){
        if(checked[i]) continue;
        dfsX(i,isX);
    }
}

void dfsY(int node, bool isY){
    checked[node]=true;
    if(node==y)isY=true;
    if(isY)subY++;
    for(int i: adj[node]){
        if(checked[i]) continue;
        dfsY(i,isY);
    }
}

int main(){
    memset(checked,false,sizeof(checked));
    long long n; cin >> n >> x >> y;
    x--; y--;
    for(int i=0; i<n-1; i++){
        int u,v; cin >> u >> v; u--;v--;
            adj[u].push_back(v); adj[v].push_back(u);
    }
    dfsX(y,false);
    memset(checked,false,sizeof(checked));
    dfsY(x,false);
    //cout << subX  << " " << subY << "\n";
    cout << (long long)n*(n-1)-(long long)subX*subY << "\n";
}