#include <bits/stdc++.h>
using namespace std;
int adj[201][201];
int dist[201][201];
const int INF=1e8;

void init(int n){
	for(int i=1; i<=n; i++){
		for(int j=1; j<=n; j++){
			if(i==j) {
				dist[i][j]=0;
			} else if(adj[i][j]!=0){
				dist[i][j]=adj[i][j];
				
			}else {
				dist[i][j]=INF;
			}
		}
	}
}

void fwa(int n){
	for(int k=1; k<=n; k++){
		for(int i=1; i<=n; i++){
			for(int j=1; j<=n; j++){
				dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
			}
		}
	}
}

int main(){
	int n,m,q;
	cin >> n >> m >> q;
	for(int i=0; i<m ;i++){
		int u,v,w;
		cin >> u >> v >> w;
		adj[u][v]=adj[v][u]=min(w,(adj[v][u]==0?INF:adj[v][u]));
	}
	init(n);
	/*
	for(int i=1; i<=n; i++){
		for(int j=1; j<=n; j++){
			cout << dist[i][j] << " ";
		}
		cout << "\n";
	}
	*/
	fwa(n);
	int ans=0;
	int prev,curr;
	cin >> prev;
	for(int i=1; i<q; i++){
		cin >> curr;
		ans+=dist[prev][curr];
		prev=curr;
	}
	cout << ans << "\n";
}