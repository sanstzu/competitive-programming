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

int main(){
	start;
	tcase{
		ll a,b,x,y,n;
		cin >> a >> b >> x >> y >> n;
		ll remainder,ansa,ansb;
		if(((a-x)+(b-y))<n){
			cout << x*y << "\n";
			continue;
		}
		if(a-x>=n){
			ansa=(a-n)*b;
		}else if ((b-(n-(a-x)))>=y){
			remainder=n-(a-x);
			ansa=x*(b-(n-(a-x)));
		}
		if(b-y>=n){
			ansb=(b-n)*a;
		}else{
			remainder=n-(b-x);
			ansb=y*(a-(n-(b-y)));
		}
		cout << min(ansa,ansb) << "\n";
	}
}
/*
1
12343 43 4543 39 123212
*/