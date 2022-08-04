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
typedef priority_queue<int> pq;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef vector<short> vs;
typedef deque<int> di;

// (y-x+1)%(n+1)=0
// 13 ... ... ... ... 22


ll largeFac(ll a, ll max){
	for (int i=max; i>0; i--){
		if(a%i==0) return i;
	}
}

int main(){
	start;
	tcase{
		ll n,x,y;
		cin >> n >> x >> y;
		if(n<3){
			cout << x << " " << y << "\n";
			continue;
		}
		ll between=largeFac(y-x,n-1)-1;
		ll diff = (y-x)/(between+1);
		ll numbef = min((x-1)/diff,n-between-2);
		ll mini = x-numbef*diff;
		ll maxi = y+diff*(n-numbef-between-2);
		for (ll i=mini; i<=maxi ; i+=diff){
			cout << i << " ";
		}
		cout << "\n";
	}
}