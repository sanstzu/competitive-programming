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
	float x1,y1,r1,x2,y2,r2;
	cin >> x1 >> y1 >> r1;
	cin >> x2 >> y2 >> r2;
	if(sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2))>(r1+r2)||(sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2))<r1 && r2<r1)||(sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2))<r2 && r1<r2)){
		cout << "tidak bersentuhan\n";
	} else {
		cout << "bersentuhan\n";
	}
}