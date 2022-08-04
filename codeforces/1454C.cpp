#include <bits/stdc++.h>
#define start ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define f first
#define s second
#define tcase int t; cin >> t; while(t--)
const int MAXI=2e5+1;
const int intMAX=2e9;
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

void solve(){
	int n; cin >> n;
		if(n==1){
			int temp; cin >> temp;
			cout << "0\n";
			return;
		}
		bool called[n+1]; for(int i=0; i<n+1; i++)called[i]=false;
		map<int,int> arr;
		int prev; cin >> prev;arr[prev]++;called[prev]=true;
		for(int i=1; i<n-1; i++){
			int temp; cin >> temp;
			if(temp!=prev){
				if(called[temp]){
					arr[temp]++;
				} else {
					arr[temp]=2;
					called[temp]=true;
				}
				prev=temp;
			}
		}
		int temp; cin >> temp;
		if(temp==prev){
			arr[temp]--;
		} else {
			if(!called[temp]) arr[temp]++;
		}
		int ans=2e9;
		for(pii i:arr){
			//cout << i.f << " " << i.s << "\n";
			ans=min(ans,i.s);
		}
		cout << ans <<"\n";
}

int main(){
	start;
	tcase{
		solve();
	}
}