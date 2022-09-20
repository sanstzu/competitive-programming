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
bool done[100][100];
int val[100][100];

void init(){
	for(int i=0; i<100; i++){
		for(int j=0; j<100; j++){
			done[i][j]=false;
			val[i][j]=0;
		}
	}
}

int lps(string str, int l, int r){
	if(done[l][r]) return val[l][r];
	if(l==r) return 1;
	if(l+1==r && str[l]==str[r]) return 2;
	if(str[l]==str[r]){
		int ans=2+lps(str,l+1,r-1);
		val[l][r]=ans;
		done[l][r]=true;
		return ans;
	} else {
		int ans=max(lps(str,l+1,r),lps(str,l,r-1));
		val[l][r]=ans;
		done[l][r]=true;
		return ans;
	}
}

int main(){
	start;
	int t;
	cin >> t;
	while(t--){
		init();
		string str;
		cin >> str;
		int len = str.length();
		cout << lps(str,0,len-1) << "\n";
	}
}