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

void solve(){
	int n,k;
	cin >> n >> k;
	ll ans=0;
	map<ll,ll> count;
	forn(i,0,n){
		ll a;
		cin >> a;
		ll dif=k-a;
		dif=((dif%k)+k)%k;
		if(dif==0) continue;
		ll curr=count[dif]*k+dif+1;
		ans=max(ans,curr);
		count[dif]++;
	}
	cout << ans << "\n";
}

int main(){
	start;
	int t;
	cin >> t;
	while (t--) solve();
}