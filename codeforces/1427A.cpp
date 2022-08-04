#include <bits/stdc++.h>
using namespace std;

void swap(int arr[], int a, int b){
	int temp=arr[b];
	arr[b]=arr[a];
	arr[a]=temp;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t; cin>>t;
	while(t--){
		int n;
		cin >> n;
		int sum=0;
		vector<int> arr;
		for(int i=0; i<n; i++){
			int temp;
			cin >> temp;
			arr.push_back(temp);
			sum+=temp;
		}
		bool anss=true;
		if(sum==0){
			cout << "NO\n";
		} else {
			if(sum>0){
				sort(arr.begin(), arr.end(), greater<int>());
			} else {
				sort(arr.begin(), arr.end());
			}
				cout << "YES\n";
			for(int i: arr){
				cout << i << " ";
			}
			cout << "\n";
		}
	
		
	}
}