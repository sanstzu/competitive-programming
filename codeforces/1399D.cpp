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
typedef priority_queue<int> pq;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef vector<short> vs;
typedef deque<int> di;


int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	tcase{
		int n;
		string str;
		cin >> n;
		cin >> str;
		vector<int> ans(n);
		stack<int> one;
		stack<int> zero;
		for(int i=0; i<n ;i++){
			int pos=one.size()+zero.size();
			if(str[i]=='0'){
				if(one.empty()){
					zero.push(pos);
				} else {
					pos=one.top();
					one.pop();
					zero.push(pos);
				}
			} else {
				if(zero.empty()){
					one.push(pos);
				} else {
					pos=zero.top();
					zero.pop();
					one.push(pos);
				}
			}
			ans[i]=pos;
		}
		cout << one.size() + zero.size() << endl;
		for(auto i: ans) cout << i+1 << " ";
		cout << endl;
	}
}

//TLE 
/*
int main(){
	start;
	tcase{
		int len;
		cin >> len;
		string str;
		cin >> str;
		bool bin[len];
		int sub[len];
		for (int i=0; i<len ; i++){
			bin[i]=str[i]-48;
			sub[i]=0;
		}
		int count =1;
		for(int i=0; i<len; i++){
			if(sub[i]==0){
				sub[i]=count;
				bool temp=bin[i];
				for(int j=i+1; j<len; j++){
					if(bin[j]!=temp && sub[j]==0){
						sub[j]=count;
						temp=!temp;
					}
				}
				count++;
			}
		}
		cout << count-1<<"\n";
		cout << sub[0];
		for (int i=1; i<len; i++){
			cout << " " << sub[i];
		}
		cout <<  "\n";
	}
}
*/