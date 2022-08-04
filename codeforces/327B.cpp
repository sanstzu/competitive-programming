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

bool primecheck[10000001];
vector<int> prime;

void init(){
	primecheck[1]=false;
	for(int i=2; i<10000001; i++){
		primecheck[i]=true;
	}
	for(int i=2; i<10000001; i++){
		if(primecheck[i]){
			for(int j=i; j<10000001; j+=i){
				primecheck[j]=false;
			}
			prime.push_back(i);
		}
	}
}


int main(){
	start;
	init();
	int n;
	cin >> n;
	for(int i=0; i<n; i++){
		cout << prime[i] << " ";
	}
}