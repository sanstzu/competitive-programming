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

void solve(int arr[]){
	if (arr[0]==arr[1] && arr[1]==arr[2]){
		cout << "YES\n";
		cout << arr[0] << " " << arr[0] << " " << arr[0] << "\n";
	} else if (arr[0]==arr[1]){
		if(arr[0]>arr[2]){
			cout << "YES\n";
			cout << arr[0] << " " << arr[2] << " 1\n";
		} else {
			cout << "NO\n";
		}
	} else if(arr[2]==arr[1]){
		if(arr[1]>arr[0]){
			cout << "YES\n";
			cout << arr[1] << " " << arr[0] << " 1\n";
		} else {
			cout << "NO\n";
		}
	} else if(arr[0]==arr[2]){
		if(arr[0]>arr[1]){
			cout << "YES\n";
			cout << arr[2] << " " << arr[1] << " 1\n";
		} else {
			cout << "NO\n";
		}
	} else {
		cout << "NO\n";
	}
}

int main(){
	start;
	tcase{
		int arr[3];
		forn(j,0,3){
			cin >> arr[j];
			
		}
		solve(arr);
	}
}