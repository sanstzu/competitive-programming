#include <bits/stdc++.h>
using namespace std;
int between[(int)(2e5)];
string temp;

void solve(string str,int n, int k){
	int index=(-1-k);
	int len=str.length();
	int curr=0;
	for (int i=0; i<n ; i++){
		temp=str[i];
		if (temp=="1"){
			between[curr]=(i-index-1-2*k);
			index=i;
			curr++;
		}
	}
	between[curr]=(len-index-1-k);
	curr++;
	int ans=0;
	for (int i=0; i<curr; i++){
		if(between[i]>0){
			ans=ans+(between[i]+k)/(k+1);
		}
	}
	cout << ans << "\n";
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t,n,k;
	string str;
	cin >> t;
	for (int i=0; i<t; i++){
		cin >> n >> k;
		cin >> str;
		solve(str, n, k);
	}
}