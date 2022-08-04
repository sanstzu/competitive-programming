#include <bits/stdc++.h>
#define start ios::sync_with_stdio(0), cin.tie(0)
#define f first;
#define s second;
#define forn(i,a,b) for(int i=a;i<b;i++)
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef vector<short> vs;
typedef vector<char> vc;
typedef deque<int> di;



void solve(string str){
	int one,zero,length;
	length = str.length();
	one=0;
	zero=0;
	forn(i,0,length){
		one+=(int)str[i]-48;
	}
	zero=length-one;
	if(min(one,zero)%2==0){
		cout << "NET\n";
	} else {
		cout << "DA\n";
	}
}

int main(){
	start;
	int t;
	cin >> t;
	string temp;
	forn(i,0,t){
		cin >> temp;
		solve(temp);
	}
}