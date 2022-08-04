#include <bits/stdc++.h>
#define start ios::sync_with_stdio(0), cin.tie(0)
#define f first;
#define s second;
#define forn(i,a,b) for(int i=a;i<b;i++)
using namespace std;
typedef unsigned long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef vector<short> vs;
typedef deque<int> di;

void solve(ll n, ll r){
	ll ans = ((min(n-1,r))*(min(n-1,r)+1)/2);
	if(n<=r){
		ans++;
	}
	cout << ans << "\n";
}

int main(){
	start;
	int t;
	cin >> t;
	ll n,r;
	while(t--){
		cin >> n >> r;
		solve (n,r);
	}
}