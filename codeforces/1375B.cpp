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
//n row m column [row][column]
int t,arr[300][300],n,m;
void solve(){
	cin >> n >> m;
		forn(i,0,n){
			forn(j,0,m){
				cin >> arr[i][j];
			}
		}
	if (arr[0][0]>2||arr[n-1][0]>2||arr[0][m-1]>2||arr[n-1][m-1]>2){
		cout << "NO\n";
		return;
	}
	forn(i,0,n){
		if(arr[i][0]>3||arr[i][m-1]>3){
			cout << "NO\n";
			return;
		}
	}
	forn(i,0,m){
		if(arr[0][i]>3||arr[n-1][i]>3){
			cout << "NO\n";
			return;
		}
	}
	forn(i,1,n-1){
		forn(j,1,m-1){
			if(arr[i][j]>4){
				cout << "NO\n";
				return;
			}
		}
	}
	cout << "YES\n";
	cout << "2 ";
	forn(i,0,m-2){
		cout << "3 ";
	}
	cout << "2\n";
	forn(i,0,n-2){
		cout << "3 ";
		forn(i,0,m-2){
			cout << "4 ";
		}
		cout << "3\n";
	}
	cout << "2 ";
	forn(i,0,m-2){
		cout << "3 ";
	}
	cout << "2\n";
}

int main(){
	start;
	cin >> t;
	while(t--){
		solve();
	}
}