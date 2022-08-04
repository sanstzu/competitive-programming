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

const int MINN=(-2e9);

int main(){
	start;
	int n; cin >> n; int sum=0,minpos=2e9,maxneg=-2e9;
	for(int i=0; i<n; i++){
		int temp; cin >> temp;
		if(temp>0){
			sum+=temp; 
			if(temp%2!=0)minpos=min(minpos,temp);
		} else {
			if(temp%2!=0)maxneg=max(maxneg,temp);
		}
	}
	if(sum%2==0){
		sum-=min(minpos,-maxneg);
	}
	cout << sum <<"\n";
}