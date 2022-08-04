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
		int arr[10][n];
		for(int i=0; i<10; i++){
			for(int j=0; j<n; j++){
				arr[i][j]=0;
			}
		}
		for(int i=0; i<n; i++){
			for(int j=0; j<n; j++){
				char temp; cin >> temp; int tint=temp-'0';
				arr[tint][i]=max(arr[tint][i],max(j-0,n-1-j));
			}
		}
		for(int i=0; i<10; i++){
			int maxarea=0;
			for(int j=0; j<n; j++){
				cout << arr[i][j] << " ";
				maxarea=max(maxarea,arr[i][j]*max(j-0,n-1-j));
			}
			cout << "\n";
			//cout << maxarea << " ";
		}
		cout << "\n";
	}
}