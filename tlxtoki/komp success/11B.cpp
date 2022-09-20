#include <bits/stdc++.h>
using namespace std;
//bellman ford
vector<tuple<int,int,int>> adj;
int dist[1001];
const int INF1=2e9;
const int INF2=1e9;

void bfa(int start, int end, int n){
	for(int i=0; i<=n; i++){
		dist[i]=INF1;
	}
	dist[start]=0;
	for(int i=1; i<=n-1; i++){
		for(auto e: adj){
			int a,b,w;
			tie(a,b,w)=e;
			dist[b]=min(dist[b],dist[a]+w);
		}
	}
	bool negcyc=false;
	for(auto e:adj){
		int a,b,w;
		tie(a,b,w)=e;
		if(dist[b]>dist[a]+w && dist[b]<INF2 && dist[a]<INF2){
			negcyc=true;
			break;
		}
	}
	if(negcyc){
		cout << "Pak Dengklek tidak mau pulang\n";
	} else {
		if(dist[end]>INF2){
			cout << "Tidak ada jalan\n";
		} else {
			cout << dist[end] << "\n";
		}
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	while(t--){
		adj.clear();
		int v,e;
		cin >> v >> e;
		for(int i=0; i<e ; i++){
			tuple<int,int,int> temp;
			int a,b,w;
			cin >> a >> b >> w;
			temp = {a,b,w};
			adj.push_back(temp);
		}
		bfa(0,v-1,v);
		/*
		for(int i=0; i<v; i++){
			cout << dist[i] << "\n";
		}
		*/
	}
}
