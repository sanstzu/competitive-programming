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
		int n,c0,c1,h; cin >> n >> c0 >> c1 >> h;
		int a0=0,a1=0;
		for(int i=0; i<n; i++){
			char temp; cin >> temp;
			if((temp-'0')==0){
				a0++;
			}else {
				a1++;
			}
		}
		int ans=0;
		if(c1>c0+h){
			ans=a0*c0+a1*(c0+h);
		} else if(c0>c1+h){
			ans=a1*c1 + a0*(c1+h);
		} else {
			ans=a0*c0+a1*c1;
		}
		cout << ans << "\n";
	}
}