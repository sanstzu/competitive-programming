#include <bits/stdc++.h>
#define start ios::sync_with_stdio(0), cin.tie(0)
typedef long long ll;
using namespace std;
void solve(int p[], int n){
	vector<int> ans;
	for (int i=1; i<n; i++){
		if(((p[i]>p[i-1])!=(p[i+1]>p[i]))&&(i==1||i==n)){
			ans.push_back(p[i]);
		}
	}
	cout << ans.size() << "\n";
}

int main(){
	start;
	int t;
	cin >> t;
	int n;
	int p[(int)1e5];
	for (int i=0; i<t; i++){
		cin >> n;
		for (int j=0; j<n; j++){
			cin >> p[j];
		}
		solve(p,n);
	}
}