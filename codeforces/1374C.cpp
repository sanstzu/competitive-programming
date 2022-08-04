#include <bits/stdc++.h>
#define start ios::sync_with_stdio(0), cin.tie(0)
#define f first;
#define s second;
#define forn(i,a,b) for(int i=a;i<b;i++)
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef vector<short> vs;
typedef deque<int> di;
const int MAX=50;
short arr[MAX];

void solve(string seq, int n){
	int count=0;
	int moves=0;
	forn(i,0,n){
		if (seq[i]=='('){
			arr[i]=1;
		} else {
			arr[i]=-1;
		}
	}
	forn(i,0,n){
		count+=arr[i];
		if (count<0){
			moves++;
			count++;
		}
	}
	cout << moves << "\n";
}

int main(){
	start;
	int t,n;
	string seq;
	cin >> t;
	forn(i,0,t){
		cin >> n;
		cin >> seq;
		solve(seq,n);
	}
}