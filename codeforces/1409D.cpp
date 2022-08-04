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

int sum(ll a){
	int ans=0;
	while(a>0){
		ans+=a%10;
		a/=10;
	}
	return ans;
}

int main(){
	start;
	tcase{
		ll n,s;
		cin >> n >> s;
		if(sum(n)<=s){
			cout << 0 << "\n";
			continue;
		}
		ll ten=1, ans=0;;
		for (int i=0; i<18; i++){
			ll add=ten*(10-(n/ten)%10);
			n+=add;
			ans+=add;
			ten*=10;
			//cout << n << endl;
			if(sum(n)<=s){
				break;
			}
		}
		cout << ans << "\n";
	}
}