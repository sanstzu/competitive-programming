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

bool overlap(int arr[], int n){
	int values[7]={1,2,1,3,1,2,1};
	int count=0;
	forn(i,0,n-6){
		forn(j,i,i+7){
			if(arr[j]!=values[j-i]){
				break;
			} else {
				count++;
				continue;
			}
		}
	}
	if (count==1){
		return true;
	} else {
		return false;
	}
}

bool search(int arr[], int index, bool absol){
	int values[7]={1,2,1,3,1,2,1};
	/*
	forn(i,index,index+7){
		cout << arr[i]<< " ";
	}
	cout << "\n";
	*/
	
	
	
	if(absol){
		//cout << "absol\n";
		for(int i=index; i<index+7; i++){
			if(arr[i]!=values[i-index]) return false;
		}
	} else {
		//cout << "bruh\n";
		for(int i=index; i<index+7; i++){
			//cout << arr[i] << "\n";
			if(!((arr[i]==values[i-index])||(arr[i]==0))) return false;
		}
	}
	//cout << "True\n";
	return true;
}

int main(){
	start;
	tcase{
		int values[7]={1,2,1,3,1,2,1};
		int n;
		cin >> n;
		string str;
		cin >> str;
		int val[n];
		for(int i=0; i<n ; i++){
			if(str[i]!='?'){
				val[i]=str[i]-96;
			} else {
				val[i]=0;
			}
		}
		bool found=false;
		bool absolfound=false;
		int index;
		
		/*
		forn(i,0,n){
			cout << val[i];
		}
		cout << endl;
		*/
		
		for(int i=0; i<n-6; i++){
			if(search(val,i,found)){
				if(!found){
					//cout << "step1" << i << "\n";
					absolfound=true;
					for(int j=i; j<i+7; j++){
						if(val[j]!=values[j-i]){
							absolfound=false;
							//cout << "test\n";
						}
					}
					found=true;
					index=i;
					continue;
				} else if(absolfound==true){
					//cout << "step2" << i << "\n";
					found=false;
					break;
				} else {
					//cout << "step3" << i << "\n";
					absolfound=true;
					index=i;
				}
			}

		}
		for(int j=index; j<index+7; j++){
			if(val[j]!=values[j-index]){
				val[j]=values[j-index];
				//cout << "test\n";
			}
		}
		for(int j=0; j<n; j++){
			if(val[j]==0){
				val[j]=26;
			}
		}
		forn(j,0,n){
			
		}
		if(found&&overlap(val,n)){
			cout << "Yes\n";
			for(int i=0; i<n; i++){
				cout << (char)(val[i]+96);
			}
			cout << "\n";
		} else {
			cout << "No\n";
		}
	}
}