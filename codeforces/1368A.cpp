#include <bits/stdc++.h>
using namespace std;

void solve(long long a, long long b, long long n){
	int count=0;
	bool done=false;
	while (!done){
		if((a>n)||(b>n)){
			done=true;
		} else if(a>b){
			b+=a;
			count++;
		} else {
			a+=b;
			count++;
		}
	}
	cout << count << "\n";
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	long long a,b,n;
	cin >> t;
	for (int i=0; i<t; i++){
		cin >> a >> b >> n;
		solve(a,b,n);
	}
}