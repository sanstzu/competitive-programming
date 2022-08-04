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
typedef priority_queue<int> pqi;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef vector<short> vs;
typedef deque<int> di;

priority_queue<int> pq;

void addDigit(int a){
	switch (a){
		case 0:
			break;
		case 1:
			break;
		case 2:
			pq.push(2);
			break;
		case 3:
			pq.push(3);
			break;
		case 4:
			pq.push(3);
			pq.push(2);
			pq.push(2);
			break;
		case 5:
			pq.push(5);
			break;
		case 6:
			pq.push(5);
			pq.push(3);
			break;
		case 7:
			pq.push(7);
			break;
		case 8:
			pq.push(2);
			pq.push(2);
			pq.push(2);
			pq.push(7);
			break;
		case 9:
			pq.push(3);
			pq.push(3);
			pq.push(2);
			pq.push(7);
			break;
	}
	
}

int main(){
	start;
	ll n,number;
	cin >> n;
	cin >> number;
	while(n--){
		addDigit(number%10);
		number/=10;
	}
	while(!pq.empty()){
		cout<<pq.top();
		pq.pop();
	}
}