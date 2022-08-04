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

vector<int> angle;

int main(){
	start;
	int n; cin >> n;
	for(int i=0; i<n; i++){
		int temp; cin >> temp;
		angle.push_back(temp);
	}
	int maxx=1<<(n);
	bool solved=false;
	for(int i=0; i<maxx && !solved; i++){
		//cout << "for i " << i << "\n";
		int sum=0;
		for(int j=0; j<n; j++){
			sum=(sum+(((i>>j)&1)*2-1)*angle[j]+360)%360;
			//cout << "for (j: " << j << ") "<<  sum << "\n";
		}
		if(sum==0){
			solved=true;
		}
	}
	if(solved){
		cout << "YES\n";
	} else {
		cout << "NO\n";
	}
}