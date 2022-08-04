#include <bits/stdc++.h>
#define start ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define f first
#define s second
#define tcase int t; cin >> t; while(t--)

using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
set<int> ls,rs;
int m;
void bruteforce(vector<int> arr, int idx,  int curval, bool right){
	if(right){
		rs.insert(curval);
	} else {
		ls.insert(curval);
	}
	if(idx>=arr.size())return ;
	bruteforce(arr,idx+1,(curval+arr[idx])%m,right);
	bruteforce(arr,idx+1,(curval)%m,right);
}
int main(){
	start;
	int n; cin >> n >> m;
	if(n>1){
		int mid=(n+1)/2;
		vector<int>l,r;
		//ls.insert(0);rs.insert(0);
		for(int i=1; i<=mid; i++){
			int temp; cin >> temp; l.push_back(temp);
		}
		for(int i=mid+1; i<=n; i++){
			int temp; cin >> temp; r.push_back(temp);
		}
		bruteforce(l,0,0,0); bruteforce(r,0,0,1);
		int res=0;
		for(int i: ls){
			auto it = rs.upper_bound(m-i-1); it--;
			res=max(res,i+*it);
			//cout << i << "\n";
		}
		cout << res << "\n";
	} else {
		int temp; cin >> temp;
		cout << temp%m << "\n";
	}
}