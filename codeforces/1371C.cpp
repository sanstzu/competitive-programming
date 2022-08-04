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

void angery(){
	cout << "No\n";
}

void not_angery(){
	cout << "Yes\n";
}


void solve(ll a, ll b, ll n, ll m){
	if (a>b && m>0){
		b-=m;
		m-=m;
	} else {
		a-=m;
		m-=m;
	}
	if (a+b>=n && b>=0 && a>=0){
		not_angery();
	} else {
		angery();
	}
}

int main(){
	start;
	int t;
	cin >> t;
	ll a,b,n,m;
	while(t--){
		cin >> a >> b >> n >> m;
		solve(a,b,n,m);
	}
}