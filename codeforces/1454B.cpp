#include <bits/stdc++.h>
#define start ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define f first
#define s second
#define tcase int t; cin >> t; while(t--)

using namespace std;
typedef long long ll;
typedef pair<int,int> pii;


int main(){
	start;
	tcase{
		int n; cin >> n;
		bool erased[n+1]; for(int i=0; i<=n; i++){
			erased[i]=false;
		}
		int part[n+1];
		set<int> arr;
		for(int i=0; i<n; i++){
			int temp; cin >> temp; 
			part[temp]=i+1;
			if(arr.count(temp)>0){
				arr.erase(temp); erased[temp]=true;
			} else if(!erased[temp]){
				arr.insert(temp);
			}
		}
		if(arr.begin()!=arr.end()){
			cout <<part[*arr.begin()] << "\n";
		} else {
			cout << "-1\n";
		}
	}
}