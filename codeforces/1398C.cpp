#include <bits/stdc++.h>
#define start ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define f first
#define s second
#define forn(i,a,b) for(int i=a;i<b;i++)
#define tcase int t; cin >> t; while(t--)
/* When using tupp (tuple consists of pair<int,pair<int,int>>)
typedef pair<int,pair<int,int>> tupp;
#define fi first
#define se second.first
#define th second.second
*/

using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef vector<short> vs;
typedef deque<int> di;

int main(){
	start;
	tcase{
		string str;
		cin >> str;
		cin >> str;
		int len = str.length();
		ll temp;
		multiset<int> arr;
		arr.insert(0);
		temp =str[0]-48-1;
		arr.insert(temp);
		int maxx=temp;
		int minn=temp;
		for(int i=1; i<len; i++){
			temp=str[i]-48-1+temp;
			maxx=max(maxx,(int)temp);
			minn=min(minn,(int)temp);
			arr.insert(temp);
		}
		ll ans;
		ans =0;
		for(int i=minn; i<maxx+1; i++){
			temp=arr.count(i);
			if(temp>0){
				ans+=(temp*(temp-1))/2;
			}
		}
		cout << ans << "\n";
	}
}