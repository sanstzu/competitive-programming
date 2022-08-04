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
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef vector<short> vs;
typedef deque<int> di;

int main(){
	start;
	int t;
	cin >> t;
	for(int i=0; i<t; i++){
		int n;
		cin >> n;
		priority_queue<pii> pq;
		int temp;
		for(int i=1; i<n+1;i++){
			cin >> temp;
			pq.push({temp,i});
		}
		pii a,b,c;
		a=pq.top();
		for (int i=0; i<n-2;i++) pq.pop();
		b=pq.top();
		pq.pop();
		c=pq.top();
		pq.pop();
		if(b.f+c.f>a.f){
			cout << "-1\n";
		} else {
			priority_queue<int> ans;
			ans.push(-a.s);
			ans.push(-b.s);
			ans.push(-c.s);
			cout << -ans.top() << " ";
			ans.pop();
			cout << -ans.top() << " ";
			ans.pop();
			cout << -ans.top() << "\n";
			ans.pop();
		}
	}
}