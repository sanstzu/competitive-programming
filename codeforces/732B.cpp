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
	int n,k; cin >> n >> k;
	vector<int> seqq;vector<int> seq; vector<int> num(n,0);
	int prev; cin >> prev;
	seqq.push_back(prev);
	if(n==1){
		cout << "0\n" << prev;
		return 0;
	}
	for(int i=1; i<n; i++){
		int temp; cin >> temp;
		seqq.push_back(temp);
		seq.push_back(k-(temp+prev));
		prev=temp;
	}
	int sizee=seq.size();
	ll ans=0;
	for(int i=0; i<sizee-1; i++){
		if(seq[i]>0) {
			num[i+1]+=seq[i];
			ans+=seq[i]; seq[i+1]-=seq[i]; seq[i]=0;
		}
	}
	if(seq[sizee-1]>0){
		ans+=seq[sizee-1];
		num[sizee]+=seq[sizee-1];
	}
	cout << ans << "\n";
	for(int i=0; i<n; i++) cout << num[i]+seqq[i] << " ";
}
