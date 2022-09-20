#include <bits/stdc++.h>
using namespace std;

void solve(int n){
	int table[n+1];
	table[0]=0;
	table[1]=1;
	for (int i=2; i<=n;i++){
		table[i]=max(table[i/2] + table[i/3] + table[i/4], i);
	}
	printf("%d\n",table[n]);
	
}

int main(){
	int n;
	scanf("%d\n", &n);
	solve(n);
}