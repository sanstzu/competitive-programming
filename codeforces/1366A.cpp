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

int solve(int stick, int diamond){
	return min((stick+diamond)/3,min(stick,diamond));
}

int main(){
	start;
	int i,t,a,b;
	cin >> t;
	forn(i,0,t){
		cin >> a >> b;
		cout << solve(a,b) << "\n";
	}
}