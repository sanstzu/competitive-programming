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
	int t; cin >> t;
	while(t--){
		int  n,k;
		cin >>n>>k;
		char temp,prev='L';
		bool firstgap=true;
		int front=0,count=0, points=0, totgap=0;
		deque<int> gap;
		for(int i=0; i<n; i++){
			cin >> temp;
			if(temp=='W'){
					if(prev=='L'){
						points++;
						if(firstgap){
							front=count;
							firstgap=false;
						} else {
							gap.push_back(count);
						}
						count =0;
					} else {
						points+=2;
					}
			} else {
				count++;
				totgap++;
				//cout << "at " << totgap << "\n";
			}
			prev=temp;
		}
		sort(gap.begin(),gap.end());
		/*
		for(int i: gap){
			cout << i << " ";
		}
		cout << "\n";
		cout << totgap << "\n";
		*/
		//cout << points << "\n";
		while((k>=gap.front()) && !gap.empty()){
			k-=gap.front();
			//cout << "adding " << gap.front() <<'\n';
			points+=gap.front()*2+1;
			totgap-=gap.front();
			gap.pop_front();
		}
		points+=min(totgap,k)*2;
		if(firstgap && k>0)points--;
		cout << points << "\n";
	}
}