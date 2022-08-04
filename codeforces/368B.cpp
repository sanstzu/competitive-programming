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
	int n,m,q;
	cin >> n >> m;
	int arr[n],amount[n];
	for(int i=0; i<n; i++){
		cin >> arr[i];
	}
	unordered_set<int> num;
	for(int i=n-1; i>=0; i--){
		num.insert(arr[i]);
		amount[i]=num.size();
	}
	for(int i=0; i<m; i++){
		cin >> q;
		cout << amount[q-1] << "\n";
	}
}