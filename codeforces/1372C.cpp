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
	bool positioned=true;
	ll count=0;
	forn(i,0,n){
		if(arr[i]==i+1){
			if(positioned==false){
				count++;
				positioned=true;
			}
		} else {
			positioned=false;
		}
	}
	if (positioned==false){
		count++;
	}
	cout << count << "\n";
}

int main(){
	start;
	int n;
	tcase{
		cin >> n;
		int arr[n];
		forn(i,0,n){
			cin >> arr[i];
		}
		solve(arr,n);
	}
}