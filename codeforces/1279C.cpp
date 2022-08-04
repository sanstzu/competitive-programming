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
		int n,m; cin >> n >> m;
		ll pos[n+1];
		for(int i=1; i<=n; i++){
			int temp; cin >> temp;
			pos[temp]=i;
		}
		queue<int> order;
		ll minpos=0,taken=0,ans=0;
		for(int i=1; i<=m; i++){
			int temp; cin >> temp;
			if(pos[temp]>minpos){
				minpos=pos[temp]; ans+=2*(pos[temp]-1-taken++)+1;
			} else {
				ans++; taken++;
			}
		}
		cout << ans << "\n";
	}
}