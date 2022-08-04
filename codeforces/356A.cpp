
#include <bits/stdc++.h>
using namespace std;
 
int dsu[300002];
int par[300001];
void init(){
	for(int i=0; i<300002; i++)dsu[i]=i;
}
 
int ft(int a){
	if(dsu[a]==a)return a;
	return dsu[a]=ft(dsu[a]);
}
 
void join(int a, int b){
	int topa=ft(a),topb=ft(b);
	dsu[topb]=topa;
}
 
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int n,m; cin >> n >> m;
	init();
	int l,r,x; 
	while(m--){
		cin >> l >> r >>x;
		l=ft(l);
		while(l<=r){
			if(l==x){
				l=ft(l+1);
				continue;
			}
			dsu[l]=l+1;
			par[l]=x;
			l=ft(l);
		}
		/*
		for(int i=1; i<=n; i++) cout << dsu[i] << " ";
		cout << "\n";
		*/
	}
	par[x]=0;
	for(int i=1; i<=n ;i++) cout << par[i] << " ";
}
