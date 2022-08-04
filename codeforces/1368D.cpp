#include <bits/stdc++.h>
#define start ios::sync_with_stdio(0), cin.tie(0)
typedef long long ll;
using namespace std;

void solve(int arr[], int n){
	int bit[20]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
	int i,j;
	for (i=0; i<n; i++){
		for (j=0; (arr[i]>>j);j++){
			if((arr[i]>>j)&1){
				bit[j]+=1;
			}
		}
	}

	ll ans=0;
	ll num=0;
	for (i=0;i<n;i++){
		num=0;
		for(j=0;j<20;j++){
			if(bit[j]){
				num+=(1<<j);
				bit[j]--;
			}
		}
		ans+=num*num;
	}
	cout<<ans<<'\n';
}

int main(){
	start;
	int n ;
	cin >> n;
	int arr[n];
	for (int i=0;i<n; i++){
		cin>>arr[i];
	}
	solve(arr,n);
}