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
	string str;
	cin >> str;
	int len=str.length();
	stack<char> order;
	int win=0;
	for(int i=0; i<len; i++){
		char temp=str[i];
		if(!order.empty() && order.top()==temp){
			order.pop(); win++;
		} else {
			order.push(temp);
		}
	}
	if(win%2==1){
		cout << "Yes\n";
	} else {
		cout << "No\n";
	}
}