#include <bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--){
		int n,k; cin >> n >> k;
		set<int> checc;
		for(int i=0; i<n; i++){
			int temp; cin >> temp;
			checc.insert(temp);
		}
		if(checc.size()>k){
			cout << "-1";
		} else {
			cout << n*k << "\n";
			for(int i=0; i<n; i++){
				for(int num:checc){
					cout << num << " ";
				}
				for(int j=0; j<k-checc.size(); j++){
					cout << 1 << " " ;
				}
			}
		}
		cout << "\n";
	}
}