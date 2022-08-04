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


void solve(int n){
	int a=n;
	int facthree, factwo;
	facthree=0;
	factwo=0;
	while(a%3==0){
		a/=3;
		facthree++;
	}
	while(a%2==0){
		a/=2;
		factwo++;
	}
	if (a!=1||factwo>facthree){
		cout << "-1\n";
	} else {
		cout << 2*facthree-factwo << "\n";
	}
}

int main(){
	start;
	int t,n;
	cin >> t;
	forn (i,0,t){
		cin >> n;
		solve(n);
	}
}