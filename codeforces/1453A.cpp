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
	int t; cin>>t;
	while(t--){
		int n,m; cin >> n >> m;
		set<int> taken;
		for(int i=0; i<n; i++){
			int temp; cin >> temp; taken.insert(temp);
		}
		int ans=0;
		for(int i=0; i<m; i++){
			int temp; cin >> temp;
			if(taken.count(temp)>0)ans++;
		}
		cout << ans << "\n";
	}
}