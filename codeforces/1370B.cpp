#include <bits/stdc++.h>
#define start ios::sync_with_stdio(0), cin.tie(0)
#define f first;
#define s second;
#define forn(i,a,b) for(int i=a;i<b;i++)
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<short> vs;

void solve (short arr[], short n){
	vs even;
	vs odd;
	for (int i=0; i<n; i++){
		if(arr[i]%2==0){
			even.push_back(i+1);
		} else {
			odd.push_back(i+1);
		}
	}
	if (even.size()%2==0){
		if(even.size()>odd.size()){
			even.pop_back();
			even.pop_back();
		} else {
			odd.pop_back();
			odd.pop_back();
		}
	} else {
		even.pop_back();
		odd.pop_back();
	}
	while(odd.size()>0){
		cout << odd[odd.size()-1] << " " << odd[odd.size()-2] << "\n" ;
		odd.pop_back();
		odd.pop_back();
	}
	
	while(even.size()>0){
		cout << even[even.size()-1] << " " << even[even.size()-2] << "\n" ;
		even.pop_back();
		even.pop_back();
	}
}

int main(){
	start;
	short t,n;
	cin >> t;
	short arr[2000];
	for (int i=0; i<t; i++){
		cin >> n;
		for (int j=0; j<2*n; j++){
			cin >> arr[j];
		}
		solve(arr,2*n);
	}
}