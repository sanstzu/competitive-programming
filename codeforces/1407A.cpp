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
	tcase{
		int n,temp;
		cin >> n;
		int count[2];
		count[0]=0;
		count[1]=0;
		for(int i=0; i<n; i++){
			cin >> temp;
			if(temp==0){
				count[0]++;
			} else {
				count[1]++;
			}
		}
		if(count[1]>count[0]){
			cout << max((count[1]/2)*2,n/2) << "\n";
			for(int i=0; i<max((count[1]/2)*2,n/2); i++){
				cout << "1 ";
			}
		} else {
			cout << max((count[0]/2)*2,n/2) << "\n";
			for(int i=0; i<max((count[0]/2)*2,n/2); i++){
				cout << "0 ";
			}
		}
		cout << "\n";
	}
}