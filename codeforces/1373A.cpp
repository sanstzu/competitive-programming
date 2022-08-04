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

void solve (int a, int b, int c){
	float apd, bpd;
	apd = a;
	bpd = c/b;
	if (apd<=bpd){
		cout << "1 -1\n";
	} else if (a>c){
		cout << "-1 1\n";
	} else if (c==a && apd>bpd) {
		cout << "-1 " << b << "\n";
	} else {
		cout << "1 " << b << "\n";
	}
}

int main(){
	start;
	int t,a,b,c;
	cin >> t;
	forn (i,0,t){
		cin >> a >> b >> c;
		solve (a,b,c);
	}
}