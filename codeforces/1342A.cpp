#include <bits/stdc++.h>
#define start ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define f first
#define s second
#define forn(i,a,b) for(int i=a;i<b;i++)
#define tcase int t; cin >> t; while(t--)

using namespace std;
typedef long long ll;
typedef priority_queue<int> pqi;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef vector<short> vs;
typedef deque<int> di;

int main(){
	start;
	int t; cin >> t;
	while(t--){
		ll x,y; cin >> x >> y;
		ll a,b; cin >> a >> b;
		ll ans;
		if(b>=2*a){
			ans=(x+y)*a;
		} else {
			if(x==y){
				ans=x*b;
			} else if(x>y){
				ans=y*b+(x-y)*a;
			} else {
				ans=x*b+(y-x)*a;
			}
		}
		cout << ans << "\n";
	}
}