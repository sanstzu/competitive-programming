#include <bits/stdc++.h>
using namespace std;
priority_queue<tuple<int,int,int>> pq; // {-dist, a,b};
int wt=0; int counter=1;
int sett[100];


void merge(int dist, int a, int b){
	if(sett[a]==sett[b] && sett[b]==0){
		sett[a]=sett[b]=counter++;
		wt+=dist;
	} else if(sett[a]==0 && sett[b]!=0){
		sett[a]=sett[b];
		wt+=dist;
	} else if(sett[a]!=0 && sett[b]==0){
		sett[b]=sett[a];
		wt+=dist;
	} else if(sett[a]+sett[b]>0 && sett[a]!=sett[b]){
		int temp=sett[b];
		for(int i=0; i<100; i++){
			if(sett[i]==temp && sett[i]!=0){
				sett[i]=sett[a];
			}
		}
		wt+=dist;
	}
}

void mst(){
	while(!pq.empty()){
		auto temp=pq.top();pq.pop();
		int dist,a,b;
		tie(dist,a,b)=temp;
		dist=0-dist;
		merge(dist,a,b);
	}
	cout << wt << "\n";
}

int main(){
	int n;
	cin >> n;
	for(int i=0;i<n; i++){
		for(int j=0; j<n; j++){
			int temp;
			cin >> temp;
			if(j>i){
				pq.push({-temp,i,j});
			}
		}
	}
	mst();
}