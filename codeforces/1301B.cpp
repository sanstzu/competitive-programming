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
		int n,temp1,temp2,diff,minn,maxx;
		minn=(int)1e9+1;
		maxx=(int)-1;
		diff=0;
		cin >> n;
		cin >> temp2;
		n--;
		while(n--){
			cin >>temp1;
			if(temp1==-1 && temp2>=0){
				minn=min(minn,temp2);
				maxx=max(maxx,temp2);
			}
			if(temp1>=0 && temp2==-1){
				minn=min(minn,temp1);
				maxx=max(maxx,temp1);
			}
			if(temp1>=0 && temp2>=0){
				diff=max(diff,abs(temp1-temp2));
			}
			temp2=temp1;
		}
		int k=(minn+maxx)/2;
		diff=max(diff,max(maxx-k, k-minn));
		cout << diff << " " << k << "\n";
	}
}