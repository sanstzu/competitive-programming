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
		int x1,y1,z1,x2,y2,z2,sum;
		sum=0;
		cin >> x1 >> y1 >> z1 >> x2 >> y2 >> z2;
		int m;
		m = min(x1,z2);
		x1-=m;
		z2-=m;
		m=min(y1,x2);
		y1-=m;
		x2-=m;
		m = min(z1,y2);
		z1-=m;
		y2-=m;
		sum+=2*m;
		sum-=2*min(y1,z2);
		cout << sum << "\n";
	}
}