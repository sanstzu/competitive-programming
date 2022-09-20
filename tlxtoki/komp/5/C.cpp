#include <bits/stdc++.h>
using namespace std;
long long n;
long long power(long long x, long long y){
    if(y==0){
		return 1;
	} else {
		long long res=power(x,y/2)%n;
		if(y%2==0){
			return (res*res)%n;
		} else {
			return (((x*res)%n)*res)%n;
		}
	}
}

int main(){
    long long a,b,c;
	cin >> a >> b >> c >> n;
    a%=n;
	b%=n;
	c%=n;
	if(a!=0){
		if(b!=0){
			if(c!=0){
				cout << power(a,power(b,c)%n)+1 << "\n";
			} else {
				cout << a%n+1 << "\n";
			}
		} else {
			cout << 1%n+1 << "\n";
		}
	} else {
		cout << "1\n";
	}
	
}