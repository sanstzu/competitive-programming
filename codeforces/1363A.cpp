#include <bits/stdc++.h>
using namespace std;

void solve(int n, int x, int arr[]){
	int odd=0;
	int temp;
	for(int i=0; i<n; i++){
		if ((arr[i]%2)==1){
			odd++;
		}
	}
	int tempodd;
	if (odd%2==0){
		tempodd=odd-1;
	} else {
		tempodd=odd;
	}
	while (tempodd>x){
		tempodd-=2;
	}
	if (n-odd>=x-tempodd && tempodd>0){
		cout << "Yes" << "\n";
	} else {
		cout << "No" << "\n";
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	int n,x;
	int arr[1000];
	cin >> t;
	for (int i=0; i<t; i++){
		cin >> n >> x;
		for (int j=0; j<n; j++){
			cin >> arr[j];
		}
		solve(n,x,arr);
	}
}