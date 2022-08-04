#include <bits/stdc++.h>
#define start ios::sync_with_stdio(0), cin.tie(0)
typedef long long ll;
using namespace std;
// true a/current, false f/not
bool checkPrime(int n){
	for (int i=2; i<=ceil(sqrt(n)); i++){
		if (n%i==0){
			return false;
		}
	}
	return true;
}

void solve(int n){
	if (n==1){
		cout << "FastestFinger\n";
		return;
	} else if (n==2){
		cout << "Ashishgup\n";
		return;
	} else if (n%2==0){
		if(checkPrime(n/2)==true){
			cout << "FastestFinger\n";
			return;
		} else if ((n&(n-1))==0){
			cout << "FastestFinger\n";
			return;
		} else {
			cout << "Ashishgup\n";
			return;
		}
	} else {
		cout << "Ashishgup\n";
		return;
	}
}

int main(){
	start;
	int t,n;
	cin >> t;
	 for (int i=0; i<t; i++){
		 cin >> n;
		 solve(n);
	 }
}