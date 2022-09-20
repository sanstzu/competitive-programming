#include <bits/stdc++.h>
using namespace std;
vector<long long> sum;
int n;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	sum.push_back(1);
	for(int i=1; i<=n ; i++){
		int temp;
		cin >> temp;
		sum.push_back(sum.back()+temp);
	}
	int q;
	cin >> q;
	for(int i=0; i<q; i++){
		int num;
		cin >> num;
		vector<long long>::iterator it;
		it=lower_bound(sum.begin(),sum.end(),num);
		cout << (it-sum.begin()) << "\n";
	}
}