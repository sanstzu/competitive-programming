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
		int n;
		cin >> n;
		vector<int> arr;
		int temp;
		for(int i=0; i<n ; i++){
			cin >> temp;
			arr.push_back(temp);
		}
		temp=n-1;
		if(arr[temp-1]>=arr[temp]){
			while((arr[temp-1]>=arr[temp])&&temp>0){
				temp--;
			}
		}
		while((arr[temp-1]<=arr[temp])&& temp>0){
			temp--;
		}
		cout << temp << "\n";
	}
}