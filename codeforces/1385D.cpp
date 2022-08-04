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

int count(int n, int m, int arr[], int depth){
	int count=0;
	forn(i,n,m){
		if(arr[i]!=depth){
			count++;
		}
	}
	return count;
}

int amount(int n, int m, int arr[], int depth){
	if(n+1==m){
		if(arr[n]==depth){
			return 0;
		} else {
			return 1;
		}
	} else {
		int mid=(n+m)/2;
		//cout << amount(n,mid,arr,depth+1)<< "\n";
		//cout << count(mid,m,arr,depth) << "\n";
		//cout << amount(mid,m,arr,depth+1)+count(n,mid,arr,depth) << "\n";
		//cout << amount(mid,m,arr,depth+1)+count(n,mid,arr,depth) << "\n";
		return min((amount(n,mid,arr,depth+1)+count(mid,m,arr,depth)),(amount(mid,m,arr,depth+1)+count(n,mid,arr,depth)));
	}
}

int main(){
	start;
	tcase{
		int len;
		cin >> len;
		int arr[len];
		string str;
		cin >> str;
		forn(j,0,len){
			arr[j]=str[j]-97;
		}
		int a=(double)round(log(len)/log(2));
		cout << amount(0,len,arr,0) << "\n";
	}
}