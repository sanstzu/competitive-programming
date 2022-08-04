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
	set<char> taken;
	set<char> diag;
	for(int i=1; i<=n; i++){
		for(int j=1; j<=n; j++){
			char temp; cin >> temp;
			if(j==i || j+i==n+1){
				diag.insert(temp);
			} else {
				taken.insert(temp);
			}
		}
	}
	bool cross=true;
	if(taken.size()==1 && diag.size()==1){
		for(char tk:taken){
			for(char dii:diag){
				if(tk==dii){
					cross=false;
				}
			}
		}
	} else {
		cross=false;
	}
	if(cross==true){
		cout << "YES\n";
	} else {
		cout <<"NO\n";
	}
}