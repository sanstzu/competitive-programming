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
const int MAXX=1000000001;

int main(){
	start;
	tcase{
		int n,temp;
		priority_queue<int> pqi;
		cin >> n;
		vector<int> arr;
		int minn=MAXX;
		for(int i=0; i<n; i++){
			cin >>temp;
			arr.push_back(temp);
			pqi.push(temp);
			minn=min(minn,temp);
		}
		bool ans=true;
		for (int i=n-1; i>-1 ; i--){
			if((arr.back()%minn!=0) && (pqi.top()!=arr.back())){
					ans=false;
					break;
			}
			arr.pop_back();
			pqi.pop();
		}
		if(ans==true){
			cout << "YES\n";
		} else {
			cout << "NO\n";
		}
	}
}