#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin >> n;
	bool array[n+3][n+3]; // [x][y]
	for (int i=0; i<n+3; i++){
		for (int j=0; j<n+3; j++){
			array[i][j]=false;
		}
	}
	for (int i=1;i<=n;i++){
		array[i][i]=true;
		array[i-1][i]=true;
		array[i-1][i-1]=true;
		array[i][i-1]=true;
		array[i][i+1]=true;
		array[i+1][i]=true;
		array[i+1][i+1]=true;
	}
	cout << (3*n+4) << "\n";
	for (int i=0; i<n+3; i++){
		for (int j=0; j<n+3; j++){
			if(array[i][j]==true){
				cout << i << " " << j << "\n";
			}
		}
	}
}