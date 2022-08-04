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

void solve(int x, int y, int n){
	int modulo=n%x;
	int diff=modulo-y;
	if (diff<0){
		diff+=x;
	}
	cout << n-diff << "\n";
}


int main(){
	start;
	int t,x,y,n;
	cin >> t;
	forn(i,0,t){
		cin >> x >> y >> n;
		solve(x,y,n);
	}
}