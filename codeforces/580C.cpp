#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

vector<int> adj[100001];
bool safe[100001],visited[100001];
int count=0; int m;
void dfs(int node, int mcount){
    for(int i: adj[node]){
        if(visited[i]) continue;
        if(safe[i] && mcount+1>m)continue;
        if(adj[i].size()==1)count++;
        visited[i]=true;
        if(safe[i]){
            dfs(i,mcount+1);
            //cout << "going for 1 at " << node << "\n";
        } else {
            //cout << "going for 2 at " << node << "\n";
            dfs(i,0);
        }
        
    }
}
int main(){
    int n; cin>>n>>m;
    for(int i=1; i<=n; i++)cin >> safe[i];
    for(int i=0; i<n-1; i++){
        int a,b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    visited[1]=true;
    dfs(1,safe[1]);
    cout << count << "\n";
}