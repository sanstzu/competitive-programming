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
	int t; cin >> t;
	while(t--){
		int n; cin >> n;
		set<int> taken; bool found=false;
		for(int i=0; i<n; i++){
			int temp; cin >> temp;
			if(taken.count(temp)==0){
				taken.insert(temp);
			} else {
				found=true;
			}
		}
		if(found){
			cout << "YES\n";
		} else {
			cout << "NO\n";
		}
	}
}