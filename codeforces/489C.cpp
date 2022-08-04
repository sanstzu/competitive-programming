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
	multiset<int> amount;
	int m,s;
	int count=0;
	cin >> m >> s;
	if(m*9<s || (s==0&&m>1)){
		cout << "-1 -1\n";
		return 0;
	} else if(m==1&&s==0){
		cout << "0 0";
		return 0;
	}
	for(int i=0; i<s/9;i++){
		amount.insert(9);
		count++;
	}
	if(s%9){
		amount.insert(s%9);
		count++;
	}
	for(int i=0; i<m-(s/9)-(s%9==0?0:1);i++){
		amount.insert(0);
	}
	/*
	bool done=false;
	for(int i=1;i<10;i++){
		for(int j=0; j<amount.count(i);j++){
			cout << i;
			if(!done&&count!=m){
				done=true;
				for(int k=0; k<m-count; k++){
					cout << 0;
				}
			}
		}
	}
	if(!done&&count!=m){
		done=true;
		for(int k=0; k<m-count; k++){
			cout << 0;
		}
	}
	*/
	if(count<m){
							
		bool subtracted=false;
		cout << 1;
		for(int k=0; k<amount.count(0)-1; k++){
			cout << 0;
		}
		for(int i=1;i<=9;i++){
			for(int j=0; j<amount.count(i);j++){
				if(!subtracted){
					cout << i-1;

					subtracted=true;
					continue;
				}
				cout << i;
			}
		}
	} else {
		for(int i=1;i<=9;i++){
			for(int j=0; j<amount.count(i);j++){
				cout << i;
			}
		}
	}
	cout << " ";
	for(int i=9;i>=0;i--){
		for(int j=0; j<amount.count(i);j++){
			cout << i;
		}
	}
}