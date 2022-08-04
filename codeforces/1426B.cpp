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

struct val{
	int num[2][2];
};
int main(){
	start;
	tcase{
		int n,m;
		vector<val> arr;
		cin >> n >> m;
		bool negreflect=false;
		/*
		0
		 0
		  0
		   0
		*/
		for(int i=0; i<n; i++){
			val temp;
			for(int j=0; j<2; j++){
				cin >> temp.num[0][j] >> temp.num[1][j];
			}
			if(!negreflect){
				for(val vec: arr){
					if(vec.num[0][0]==temp.num[0][0] &&vec.num[1][1]==temp.num[1][1] &&vec.num[0][1]==temp.num[1][0] &&vec.num[1][0]==temp.num[0][1]){
						negreflect=true;
					}
				}
				if(temp.num[0][1]==temp.num[1][0]) negreflect=true;
			}
		}
		if(negreflect&&(m%2==0)){
			cout << "YES\n";
		} else {
			cout << "NO\n";
		}
	}
}