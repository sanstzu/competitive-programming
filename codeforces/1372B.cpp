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

int smallestfactor(int n){
	forn(i,2,sqrt(n)+1){
		if(n%i==0){
			return i;
		}
	}
	return 1;
}

void solve(int n){
	int temp=smallestfactor(n);
	if (temp>1){
		cout << n/temp << " " << n-(n/temp) << "\n";
	} else {
		cout << "1 " << n-1 << "\n";
	}
}

int main(){
	start;
	int n;
	tcase{
		cin >> n;
		solve(n);
	}
}