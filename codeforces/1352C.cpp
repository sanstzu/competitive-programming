#include <bits/stdc++.h>
using namespace std;

void solve(int n, int k){
	int res = k+floor((k-1)/(n-1));
	cout << res << "\n";
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int amount,n,k;
	cin >> amount;
	for (int i=0; i<amount; i++){
		cin >> n >> k;
		solve(n,k);
	}
}