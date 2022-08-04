#include <bits/stdc++.h>
#include <algorithm>
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
	vector<int> a;
	start;
	int n;
	cin >> n;
	int temp;
	a.push_back(1);
	for (int i=1; i<=n ; i++){
		cin >> temp;
		a.push_back(a[i-1]+temp);
	}
	int q;
	cin >> q;
	for (int i=0; i<q; i++){
		cin >> temp;
		int p = upper_bound(a.begin(),a.end(),temp)-a.begin();
		cout << p << "\n";
	}
	
}