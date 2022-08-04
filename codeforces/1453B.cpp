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
	int t; cin >> t;
	while(t--){
		int n; cin >> n;
		int arr[n];
		for(int i=0; i<n; i++){
			cin >> arr[i];
		}
		ll tc=0; int prevpeak=arr[0]; int mcr=abs(arr[0]-arr[1]);
		for(int i=1; i<n-1; i++){
			if(arr[i]>=arr[i-1] && arr[i]>=arr[i+1]){
				//local maximum
				tc+=abs((ll)arr[i]-prevpeak);
				prevpeak=arr[i];
				mcr=max(mcr,abs(prevpeak-max(arr[i+1],arr[i-1]))*2);
			} else if(arr[i]<=arr[i-1] && arr[i]<= arr[i+1]){
				//local minimum
				tc+=abs((ll)arr[i]-prevpeak);
				prevpeak=arr[i];
				mcr=max(mcr,abs(min(arr[i-1],arr[i+1])-prevpeak)*2);
			}
		}
		tc+=abs(prevpeak-arr[n-1]);
		mcr=max(mcr,abs(arr[n-1]-arr[n-2]));
		cout << tc-mcr << "\n";
	}
}