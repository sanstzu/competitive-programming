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
int diff[200000];

int main(){
	start;
	int n; cin >> n;
	int pos1[n+1],pos2[n+1];
	for(int i=0; i<n; i++){
		int temp; cin >> temp;
		pos1[temp]=i;
	}
	for(int i=0; i<n; i++){
		int temp; cin >> temp;
		pos2[temp]=i;
	}
	for(int i=1; i<=n; i++){
		diff[((pos1[i]-pos2[i]+n)%n)]++;
	}
	int maxi=0;
	for(int i=0; i<n; i++){
		maxi=max(maxi,diff[i]);
	}
	cout << maxi << "\n";
}