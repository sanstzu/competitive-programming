#include <iostream>
#include <vector>
using namespace std;
int num[100000];
vector<int> adj[100000];
int counter=1;

void join(int a, int b){
	if(num[a]==num[b] && num[a]==0){
		num[a]=num[b]=counter++;
		adj[num[a]].push_back(a);
		adj[num[a]].push_back(b);
	} else if(num[a]==0 && num[b]!=0){
		num[a]=num[b];
		adj[num[a]].push_back(a);
	} else if(num[a]!=0 && num[b]==0){
		num[b]=num[a];
		adj[num[a]].push_back(b);
	} else {
		int temp=num[b];
		for(auto i: adj[temp]){
			num[i]=num[a];
			adj[num[a]].push_back(i);
		}
	}
	/*
	for(int i=1; i<=5 ;i++){
		cout << num[i] << " ";
	}
	cout << "\n";
	*/
}

int main(){
	int n,q;
	cin >> n >> q;
	for (int i=0; i<q; i++){
		int func,a,b;
		cin >> func>>a >>b;
		if(func==1){
			join(a,b);
		} else {
			if((num[a]==num[b] && num[a]!=0)||a==b){
				cout << "Y\n";
			} else {
				cout << "T\n";
			}
		}
	}
	
}