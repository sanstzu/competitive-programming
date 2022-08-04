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
		int n,k; cin >> n >> k;
		int from[26],to[26],dif[26];
		for(int i=0; i<26; i++){
			from[i]=0; to[i]=0;
		}
		for(int i=0; i<n; i++){
			char temp; cin >> temp;
			from[(int)temp-'a']++;
		}
		for(int i=0; i<n; i++){
			char temp; cin >> temp;
			to[(int)temp-'a']++;
		}
		
		for(int i=0 ;i<26; i++){
			dif[i]=to[i]-from[i];
			//cout << dif[i] << " ";
		}
		//cout << "\n";
		
		int sum=0,i=0;
		while(sum<=0 && sum%k==0 && i<26){
			sum+=dif[i];
			i++;
		}
		if(sum>0 || sum%k!=0){
			cout << "No\n";
		} else {
			cout << "Yes\n";
		}
	}
}