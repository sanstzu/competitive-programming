#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(ll len){
	char sets[10]={'c','o','d','e','f','o','r','c','e','s'};
	ll count=1;
	ll arr[10]={1,1,1,1,1,1,1,1,1,1};
	for (int i=0,j=0,k=2; count<len; i++, j++){
		if(j>9){
			j=0;
			k++;
		}
		arr[j]++;
		count/=(k-1);
		count*=k;
	}
	for (int i=0; i<10; i++){
		for (int j=0; j<arr[i]; j++){
			cout << sets[i];
		}
	}
	cout << "\n";
}

int main(){
	ll k;
	cin >> k;
	solve(k);
}