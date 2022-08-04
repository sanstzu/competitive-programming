#include <bits/stdc++.h>
using namespace std;

int solve(int arr[], int n, int m){
	int i,j,temp;
	int count=0;
	temp=0;
	for (int i=0; i<n; i++){
		if (temp+arr[i]<=m){
			temp+=arr[i];
		} else {
			count++;
			temp=arr[i];
		}
	}
	if (temp>0){
		count++;
	}
	return count;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n,m;
	cin >> n >> m;
	int arr[n];
	for (int i=0; i<n; i++){
		cin >>arr[i];
	}
	cout << solve(arr,n,m);
}
