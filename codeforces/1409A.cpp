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
	int t;
	cin >> t;
	while(t--){
		int a,b,ans=0;
		cin >> a >> b;
		int temp=abs(a-b);
		ans=temp/10;
		if(temp%10>0)ans++;
		cout << ans << "\n";
	}
}