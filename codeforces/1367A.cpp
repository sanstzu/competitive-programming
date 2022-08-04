#include <bits/stdc++.h>
using namespace std;

void solve(string n){
	int len=n.length();
	int i;
	cout << n[0];
	for (i=1; i<len-1;i+=2){
		cout << n[i];
	}
	cout << n[len-1];
	cout<<"\n";
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	string a;
	for (int i=0; i<t; i++){
		cin >> a;
		solve(a);
	}
}