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
	int n,m; cin >> n >> m; //n row m column
	bool people[n][m];
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			cin >> people[i][j];
		}
	}
	int ans=0;
	//pointing to the right
	for(int i=0; i<n; i++){
		bool hit=false;
		for(int j=0; j<m; j++){
			if(people[i][j]){
				hit=true;
			} else {
				if(hit)ans++;
			}
		}
	}
	
	//pointing to the left
	for(int i=0; i<n; i++){
		bool hit=false;
		for(int j=m-1; j>=0; j--){
			if(people[i][j]){
				hit=true;
			} else {
				if(hit)ans++;
			}
		}
	}
	
	//pointing to the bot
	for(int i=0; i<m; i++){
		bool hit=false;
		for(int j=0; j<n; j++){
			if(people[j][i]){
				hit=true;
			} else {
				if(hit)ans++;
			}
		}
	}
	
	//pointing to the top
	for(int i=0; i<m; i++){
		bool hit=false;
		for(int j=n-1; j>=0; j--){
			if(people[j][i]){
				hit=true;
			} else {
				if(hit)ans++;
			}
		}
	}
	
	cout << ans << "\n";
}