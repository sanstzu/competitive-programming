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
	tcase{
		int x,y; cin >> x >> y;
		int minn=min(x,y);
		x-=minn,y-=minn;
		int ans=2*minn;
		if(x>y){
			ans+=2*x-1;
		} else if(y>x){
			ans+=2*y-1;
		}
		cout << ans << "\n";
	}
}