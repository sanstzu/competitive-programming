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
	int x,y,a,b; cin >> x >> y >> a >> b;
	vector<pii> ans;
	for(int i=a; i<=x; i++){
		for(int j=b; j<=y; j++){
			if(i<=j) break;
			ans.push_back({i,j});
		}
	}
	cout << ans.size() << "\n";
	for(pii pairr: ans){
		cout << pairr.f << " " << pairr.s << "\n";
	}
}