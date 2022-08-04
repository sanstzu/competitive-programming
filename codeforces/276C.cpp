#include <bits/stdc++.h>
#define start ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define f first
#define s second
#define forn(i,a,b) for(int i=a;i<b;i++)
#define tcase int t; cin >> t; while(t--)
#define lsone(s) (s&(-s))
using namespace std;
typedef long long ll;
typedef priority_queue<int> pqi;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef vector<short> vs;
typedef deque<int> di;
int n;
vector<int> fw(200002);


void update(int idx, int val){
	while(idx<=n){
		fw[idx]+=val;
		idx+=lsone(idx);
	}
}

int getsum(int idx){
	int ptr=idx-1;
	int sum=0;
	while(idx>0){
		sum+=fw[idx];
		idx-=lsone(idx);
	}
	return sum;
}

int main(){
	start;
	int q; cin >> n >> q;
	int arr[n+1],count[n+1];
	priority_queue<int> num;
	for(int i=1; i<=n; i++){
		cin >> arr[i];
		num.push(arr[i]);
		count[i]=0;
	}
	//vector<int> fw(n+2,0);
	for(int i=0; i<q; i++){
		int templ,tempr; cin >> templ >> tempr;
		update(templ,1);update(tempr+1,-1);
		//for(int i=1; i<=n; i++) cout << fw[i] << " ";
		//cout << "\n";
	}
	priority_queue<int> freq;
	for(int i=1; i<=n; i++){
		freq.push(getsum(i));
	}
	ll sum=0;
	for(int i=0; i<n; i++){
		sum+=(ll)num.top()*(ll)freq.top();
		num.pop();freq.pop();
	}
	cout << sum <<"\n";
}