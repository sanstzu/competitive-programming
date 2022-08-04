#include <bits/stdc++.h>
#define lsone(s) (s & (-s))
using namespace std;
typedef long long ll;
ll n,k;
ll dp[12][100001];
ll bit[12][100001];
ll pos[100001];

void update(ll j, ll i, ll val){
	for(;i<=n; i+=lsone(i)){
		bit[j][i]+=val;
	}
}

ll query (ll idx, ll i){
	ll ans=0;
	for(;i>=1; i-=lsone(i)){
		ans+=bit[idx][i];
	}
	return ans;
}
int main(){
	cin >> n >> k;
	for(int i=1; i<=n; i++){
		int temp; cin >> temp;
		pos[temp]=i;
	}
	for(ll i=1; i<=n; i++){
		for(ll j=1; j<=k+1; j++){
			dp[j][pos[i]]=query(j-1,pos[i]-1);
			if(j==1)dp[j][pos[i]]=1;
			update(j,pos[i],dp[j][pos[i]]);
		}
	}
	ll ans=0;
	for(int i=1; i<=n; i++){
		ans+=dp[k+1][i];
	}
	cout << ans << "\n";
}