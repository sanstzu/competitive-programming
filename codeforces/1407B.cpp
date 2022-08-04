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
		int n;
		cin >> n;
		int temp,maxx,maxxind;
		maxx=0;
		vector<int> val;
		for(int i=0; i<n; i++){
			cin >> temp;
			val.push_back(temp);
			if(temp>maxx){
				maxx=temp;
				maxxind=i;
			}
		}
		int prevgcd=maxx;
		for(int i=0; i<n ;i++){
			cout << val[maxxind] << " ";
			val[maxxind]=-1;
			maxx=0;
			int gcdd;
			for(int j=0; j<n; j++){
				gcdd=__gcd(prevgcd,val[j]);
				if(gcdd>maxx){
					maxx=gcdd;
					maxxind=j;
				}
			}
			prevgcd=maxx;
		}
		cout << "\n";
	}
}