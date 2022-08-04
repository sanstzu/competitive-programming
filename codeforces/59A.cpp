#include <bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	string input;
	cin >> input;
	int len = input.length();
	int temp;
	int lowercase=0;
	for (int i=0; i<len; i++){
		temp = input[i];
		if (temp>96){
			lowercase++;
		}
	}
	if (len>2*lowercase){
		for (int i=0; i<len; i++){
		temp = input[i];
		if (temp>96){
			input[i]-=32;
			}
		}
	} else {
		for (int i=0; i<len; i++){
		temp = input[i];
		if (temp<96){
			input[i]+=32;
			}
		}
	}
	cout << input << "\n";
}