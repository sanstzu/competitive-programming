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
		int len = str.length();
		priority_queue<int> ans;
		for (int i=0; i<len; i++){
			if(str[i]==49){
				int count=1;
				while (str[i+1]==49 && i<len){
					count++;
					i++;
				}
				ans.push(count);
			}
		}
		int maxscore=0;
		while(!ans.empty()){
			maxscore+=ans.top();
			for(int i=0; i<2 && !ans.empty();i++){
				ans.pop();
			}
		}
		cout << maxscore << "\n";
	}
}