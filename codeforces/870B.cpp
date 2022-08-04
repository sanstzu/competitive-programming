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
	int minn=2e9,maxx=-2e9,maxminn=-2e9;
	int n,k; cin >> n >> k;
	for(int i=0; i<n; i++){
		int temp; cin >> temp;
		minn = min(minn,temp);
		maxx= max(maxx,temp);
		if(minn==temp || i==n-1){
			maxminn=max(maxminn,temp);
		}
	}
	if(k>2){
		cout << maxx;
	} else if (k==2){
		cout << maxminn;
	} else {
		cout << minn;
	}
}