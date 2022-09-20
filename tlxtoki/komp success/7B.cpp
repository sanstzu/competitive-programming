#include <bits/stdc++.h>
using namespace std;
//works :)
void solve(int n, int k, int wt[], int v[]){
	// n : capacity
	// k : item no.
	// w : item weight array
	// v : item value
	int table[k+1][n+1];
	int i,j;
	// table[item no][current capacity]
	for (i=0; i<=k; i++){
		for (j=0; j<=n; j++){
			if (i==0||j==0) {
				table[i][j]=0;
			} else if (wt[i-1] <= j){
				table[i][j] = max(v[i-1]+table[i-1][j-wt[i-1]], table[i-1][j]);
			} else {
				table[i][j] = table[i-1][j];
			}
		}
	}
	//debug#1
	/*
	for (int a=0; a<=k; a++){
		for (int b=0; b<=n; b++){
			printf("table[%d][%d]: %d\n",a,b,table[a][b]);
		}
	}
	*/
	int maxi=0;
	int minweight;
	for (j=n; j>=0; j--){
		if (maxi<=table[k][j]){
			maxi=table[k][j];
			minweight=j;
		}
	}

	
	//it would return table[k][minweight] since minweight is less than the maximum capacity
	//hence it is acceptable
	int res = table[k][minweight];
	j = minweight;
	bool included[k];
	for (int a=0; a<k; a++){
		included[a]=false;
	}
	for (int i=k; i>0 && res>0; i--){
		//checks if the k th item is being taken or not
		if (res != table[i-1][j]){
			included[i-1]=true;
			res = res - v[i-1];
			j = j - wt[i-1];
		}
	}
	//debug#2
	//printf("minweight: %d\ntable:%d\n", minweight, table[k][minweight]);
	for (int a=0;a<k;a++){
		if (included[a]){
			printf("%d\n", a+1);
			//printf("%d: true\n", a+1);
		} else {
			//printf("%d: false\n", a+1);
		}
	}
	

	//return table[k][n];
}

int main(){
	int n,k;
	scanf("%d %d", &n, &k);
	int wt[k];
	int v[k];
	for (int i=0; i<k; i++){
		scanf("%d %d", &wt[i], &v[i]);
	}
	solve(n,k,wt,v);
}

/*
Contoh Masukan 1
11 3
10 30
6 17
5 14
Contoh Keluaran 1
2
3
Contoh Masukan 2
30 4
11 2
12 2
13 2
14 2
Contoh Keluaran 2
1
2
Contoh Masukan 3
30 3 
10 1
15 2
25 3
Contoh Keluaran 3
1
2*/