#include <iostream>
#include <cmath>
using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	long long n,m,a;
	cin >> n >> m >>a;
	cout << (long long)((m+a-1)/a)*((n+a-1)/a);
}