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
		int n,m; cin >> n >> m;
		for(int i=0; i<n; i++){
			for(int j=0; j<m; j++){
				int temp; cin >> temp;
				if(temp%2 != (i+j)%2){
					temp++;
				}
				cout << temp << " ";
			}
			cout << "\n";
		}
	}
}