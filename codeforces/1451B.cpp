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
		int n,q; cin >> n >> q;
		vector<int> sum(n+1,0);
		vector<int> val(n+1,0);
		for(int i=1; i<=n; i++){
			char temp; cin >> temp;
			val[i]=temp-'0';
			sum[i]+=sum[i-1]+(temp-'0');
		}
		/*
		for(int i: val) cout << i << " ";
		cout << "\n";
		for(int i: sum) cout << i << " ";
		cout << "\n";
		*/
		while(q--){
			bool found=false;
			int l,r; cin >> l >> r;
			if(l>1){
				if(val[l]==0 && ((l-1==1 && val[l-1]==0)||(l-1!=1 && sum[l-1]!=l-1))){
					found=true;
				} else if(val[l]==1 && ((l-1==1 && val[l-1]==1)||(l-1!=1 && sum[l-1]!=0))){
					found=true;
				}
			}
			if(r<n){
				if(val[r]==0 && ((r+1==n && val[r+1]==0) ||(r+1!=n && sum[n]-sum[r]!=n-rnf ))){
					found=true;
				} else if(val[r]==1 && ((r+1==n && val[r+1]==1) || (r+1!=n && sum[r]!=sum[n]))){
					found=true;
				}
			}
			if(found){
				cout << "YES\n";
			} else {
				cout << "NO\n";
			}
		}
	}
}