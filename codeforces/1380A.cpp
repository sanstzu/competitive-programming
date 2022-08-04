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
	bool solve=false;
	int ans;
	for(int i=1; i<n-1; i++){
		if(arr[i]>arr[i-1] && arr[i]>arr[i+1]){
			solve=true;
			ans=i+1;
			break;
		}
	}
	if(solve){
		cout << "YES\n";
		cout << ans-1 << " " << ans << " " << ans+1 << "\n";
	} else {
		cout << "NO\n";
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t,arr[1000],n;
	cin >> t;
	for(int i=0; i<t; i++){
		cin >> n;
		for(int j=0; j<n;j++){
			cin >> arr[j];
		}
		solve(arr,n);
	}
}