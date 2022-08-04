#include <bits/stdc++.h>
#define start ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define f first
#define s second
#define tcase int t; cin >> t; while(t--)

using namespace std;
typedef long long ll;
typedef pair<int,int> pii;


int main(){
	start;
	tcase{
		int n; cin >> n;
		for(int i=0; i<n; i++){
			cout << (i+1)%n+1 << " ";
		}
		cout << "\n";
	}
}