#include <bits/stdc++.h>
using namespace std;

void solve(deque<int> arr){
	int a,b,min,count;
	a=0;
	b=0;
	count=0;
	bool turn=true; // true for a, false for b
	min=0;
	int temp=0;
	while (!arr.empty()){
		temp=0;
		if (turn){
			while(!temp>min && !arr.empty()){
				temp+=arr.front();
				arr.pop_front();
			}
			cout << temp << endl;
			min=temp;
			a+=temp;
			turn=false;
		} else {
			while(!temp>min && !arr.empty()){
				temp+=arr.back();
				arr.pop_back();
			}
			min=temp;
			b+=temp;
			turn=true;
		}
		count++;
	}
	cout << count << " " << a << " " << b << "\n";
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	int n;
	int temp;
	for (int i=0; i<t; i++){
		cin >> n;
		deque<int> arr;
		for(int j=0; j<n; j++){
			cin >> temp;
			arr.push_back(temp);
		}
		solve(arr);
	}
}
