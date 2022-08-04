#include <bits/stdc++.h>
#define start ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define f first
#define s second
#define forn(i,a,b) for(int i=a;i<b;i++)
#define tcase int t; cin >> t; while(t--)
/* When using tupp (tuple consists of pair<int,pair<int,int>>)
typedef pair<int,pair<int,int>> tupp;
#define fi first
#define se second.first
#define th second.second
*/

using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef vector<short> vs;
typedef deque<int> di;

int main(){
	start;
	tcase{
		int r,g,b,w;
		cin >> r >> g >> b >> w;
		int modsum = r%2 + g%2 +b%2 + w%2;
		int amount = r+g+b+w;
		if(amount%2==0){
			if(modsum==0||(modsum==4&&(r>0&&b>0&&g>0))){
				cout << "Yes\n";
			} else {
				cout << "No\n";
			}
		} else {
			if(modsum==1||(modsum==3&&(r>0&&b>0&&g>0))){
				cout << "Yes\n";
			} else {
				cout << "No\n";
			}
		}
	}
}