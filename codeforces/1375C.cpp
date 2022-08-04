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

int main(){
	start;
	int t,n,first,last,temp;
	cin >> t;
	while (t--){
		cin >> n;
		int first;
		forn(i,0,n){
			if(i==0){
				cin >> first;
			} else if(i==n-1){
				cin >> last;
			} else {
				cin >> temp;
			}
		}
		if (first<last){
			cout << "YES\n";
		} else {
			cout << "NO\n";
		}
	}
}