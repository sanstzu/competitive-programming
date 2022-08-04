#include <bits/stdc++.h>
using namespace std;

int main(){
	int n; cin >> n;
	int h[n];
	for(int i=0; i<n; i++){
		cin >> h[i];
	}
	int maxh[n];int maxi=-1;
	maxh[n-1]=0;
	for(int i=n-1; i>=0; i--){
		if(h[i]>maxi){
			maxh[i]=0; maxi=h[i];
		} else {
			maxh[i]=maxi-h[i]+1;
		}
	}
	for(int i=0; i<n ; i++){
		cout << maxh[i] << " ";
	}
	cout << "\n";
}

