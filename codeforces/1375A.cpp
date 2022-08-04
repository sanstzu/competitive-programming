#include <bits/stdc++.h>
#define start ios::sync_with_stdio(0), cin.tie(0)
#define f first;
#define s second;
#define forn(i,a,b) for(int i=a;i<b;i++)
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef vector<short> vs;
typedef deque<int> di;
int diff[99];

void solve(int arr[], int n){
	bool negative=true;
	forn(i,0,n-1){
		if(arr[i+1]-arr[i]<=0){
			if(!negative){
				if(-arr[i+1]-arr[i]>=0){
					arr[i+1]=-arr[i+1];
				} else {
					arr[i]=-arr[i];
				}
			}
		}else{
			if(negative){
				if(-arr[i+1]-arr[i]<=0){
					arr[i+1]=-arr[i+1];
				} else {
					arr[i]=-arr[i];
				}
			}
		};
		negative=!negative;
	}
	forn(i,0,n){
		cout << arr[i] << " ";
	}
	cout << "\n";
}

int main(){
	start;
	int t,arr[99],n;
	cin >> t;
	while(t--){
		cin >> n;
		forn(i,0,n){
			cin >> arr[i];
		}
		solve(arr,n);
	}
}