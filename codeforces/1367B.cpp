#include <bits/stdc++.h>
using namespace std;

void solve (int arr[], int n){
	int i;
	int even=0;
	int odd=0;
	for (i=0; i<n; i++){
		if ((i%2)!=(arr[i]%2)){
			if(arr[i]%2==0){
				even++;
			} else {
				odd++;
			}
		}
	}
	if (even==odd){
		cout << even << "\n";
	} else {
		cout << "-1\n";
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t,arr[40],n;
	cin >> t;
	for (int i=0; i<t; i++){
		cin >> n;
		for (int j=0; j<n; j++){
			cin >> arr[j];
		}
		solve(arr,n);
	}
}