#include <bits/stdc++.h>
#define start ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define f first
#define s second
#define forn(i,a,b) for(int i=a;i<b;i++)
#define tcase int t; cin >> t; while(t--)

using namespace std;
typedef long long ll;
typedef priority_queue<int> pqi;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef vector<short> vs;
typedef deque<int> di;

int main(){
	start;
	tcase{
		int n; cin >> n;
		if(n==1){
			cout << 0 << "\n";
		} else if(n==2){
			cout << 1 << "\n";
		} else if(n==3){
			cout << 2 << "\n";
		} else {
			if(n%2==0){
				cout << 2 << "\n";
			} else {
				cout << 3 << "\n";
			}
		}
	}
}