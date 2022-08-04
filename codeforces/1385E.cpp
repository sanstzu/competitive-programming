#include <bits/stdc++.h>
#define start ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define f first
#define s second
#define forn(i,a,b) for(int i=a;i<b;i++)
#define tcase int t; cin >> t; while(t--)
/* When using tupp (tuple consists of pair<int,pair<int,int>>)
typedef pair<int,pair<int,int>> tupp;
#define fi first
#define se second.first
#define th second.second
*/

using namespace std;
typedef long long ll;
typedef priority_queue<int> pq;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef vector<short> vs;
typedef deque<int> di;

bool isCyclic_util(vector<int> adj[], vector<bool> visited, int curr){
	if(visited[curr]==true) return false;
	visited[curr]==true;
	bool FLAG = false;
	for (int i=0; i<adj[curr].size();i++){
		FLAG = isCyclic_util(adj,visited,adj[curr][i];
		if(FLAG) return true;
	}
	return false;
}

bool isCyclic(int v, vector<int> adj[]){
	vector<bool> visited(v,false);
	bool FLAG = false;
	for (int i=1; i<v; i++){
		visited[i]=true;
		for (int j=0; j<adj[i].size(); j++){
			FLAG = isCyclic_util(adj,visited,adj[i][j]);
			if(FLAG) return true;
		}
		visited[i]=false;
	}
	return false;
}

int main(){
	start;
	int t;
	cin >> t;
	while (t--){
		int n,n;
		cin >> n >> m;
		vector<int> adj[n];
		vector<pii> undir;
		for(int i=0; i<m ; i++){
			int t,x,y;
			cin >> t >> x >> y; 
			if (t==1){
				adj[x].push_back(y);
			} else {
				undir.push_back();
			}
		}
		if(isCyclic(n,adj)){
			cout << "NO\n";
		} else {
			cout << "YES\n";
			for(int i
		}
	}
}