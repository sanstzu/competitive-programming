#include <bits/stdc++.h>
using namespace std;

void solve(int arr[], int n, int x){
	int divisible=0;
	int sum=0;
	int begin=-1;
	int end=-1;
	for(int i=0; i<n; i++){
		if(arr[i]%x==0){
			divisible++;
			
		}
		sum+=arr[i];
		if(begin==-1 && arr[i]%x!=0){
			begin=i;
		}
		if(i>end && arr[i]%x!=0){
			end=i;
		}
	}
	if (divisible==n){
		cout << -1 << "\n";
	} else if (sum%x==0){
		cout << n-min(begin+1,n-end) << "\n";
	} else {
		cout << n << "\n";
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	int n,x;
	int arr[(int)1e5];
	cin >> t;
	for (int i=0; i<t; i++){
		cin >> n >> x;
		for (int j=0; j<n; j++){
			cin >> arr[j];
		}
		solve(arr,n,x);
	}
}