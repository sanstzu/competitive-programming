#include <bits/stdc++.h>
#define start ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define f first
#define s second
#define forn(i,a,b) for(int i=a;i<b;i++)
#define tcase int t; cin >> t; while(t--)
/* When using tupp (tuple consists of pair<int,pair<int,int>>)
typedef pair<int,pair<int,int>> tupp;
#define fi first
#define se second.first
#define th second.second
*/

using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef vector<short> vs;
typedef deque<int> di;

void solve(int arr[], int n){
	vector<int> ans;
	bool added[n+1];
	for(int i=0; i<n+1; i++){
		added[i]=false;
	}
	int max=2*n;
	for(int i=0; i<max; i++){
		if(!added[arr[i]]){
			ans.push_back(arr[i]);
			added[arr[i]]=true;
		}
	}
	for(int i=0; i<n; i++){
		cout << ans[i] << " ";
	}
	cout << "\n";
}

int main(){
	start;
	tcase{
		int n;
		cin >> n;
		int arr[2*n];
		for(int j=0; j<2*n ; j++){
			cin >> arr[j];
		}
		solve(arr,n);
	}
}