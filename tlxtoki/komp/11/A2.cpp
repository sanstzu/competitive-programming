#include <bits/stdc++.h>
#define f first
#define s second
using namespace std;
typedef pair<int,int> pii;
const int MAX=1e9;

vector<pii> adj[2501]; // {index no, jarak}
int dist[2501];

void init(){
	for(int i=0; i<2501; i++){
		dist[i]=MAX;
	}
}

void dijkstra(int start, int end){
	priority_queue<pii> pqi; // {-jarak, index no};
	dist[start]=0;
	pqi.push({0,start});
	while(!pqi.empty()){
		pii current=pqi.top();
		pqi.pop();
		current.f=-current.f;
		if(dist[current.s]<current.f) continue;
		for(auto a:adj[current.s]){
			if(a.s + current.f < dist[a.f]){
				dist[a.f]=a.s+current.f;
				pqi.push({-dist[a.f],a.f});
			}
		}
	}
	cout << dist[end] << "\n";
}

int main(){
	init();
	int v,e,a,b;
	cin >> v >> e >> a >> b;
	for(int i=0; i<e; i++){
		int x,y,z;
		cin >> x >> y >> z;
		adj[x].push_back({y,z});
		adj[y].push_back({x,z});
	}
	dijkstra(a,b);
} 