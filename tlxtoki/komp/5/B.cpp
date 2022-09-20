#include <bits/stdc++.h>
using namespace std;

long long power(int x, int y){
    if (y == 0) 
        return 1; 
    else if (y % 2 == 0) 
        return (long long)(power(x, y / 2) * power(x, y / 2))%1000000; 
    else
        return (long long)(x * power(x, y / 2) * power(x, y / 2))%1000000; 
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int a,b;
    cin >> a >> b;
    a%=1000000;
    b%=1000000;
    string ans = to_string(power(a,b));
    if ((b*floor(log10(a)))>7){
		for (int i=0; i<(6-ans.length()); i++){
			cout << 0;
		}
	}
    cout << ans << "\n";
}
