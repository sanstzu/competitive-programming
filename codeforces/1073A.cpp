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
	int n; cin >> n;
	if(n>1){
		char prev,temp; cin >> temp;
		bool found=false;
		for(int i=0; i<n-1 && !found; i++){
			prev=temp;
			cin >> temp;
			if(temp!=prev){
				found=true;
			}
		}
		if(found){
			cout <<"YES\n";
			cout << prev<<temp;
		} else {
			cout << "NO\n";
		}
	} else {
		cout << "NO\n";
	}
}