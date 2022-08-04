#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
typedef pair<int,int> pii;

int main(){
    ios::sync_with_stdio(0);
    cout.tie(0); cin.tie(0);
    int t=1;
    while(t--){
        int n,q; cin >> n >> q;
        char arr[n]; for(int i=0; i<n; i++) cin >> arr[i];
        //bool isABC[n]; memset(isABC, 0, sizeof(isABC));
        int cnt = 0;
        
        for(int i=2; i<n; i++){
            if(arr[i-2]=='a' && arr[i-1]=='b' && arr[i]=='c'){
                cnt++;
                i+=2;
            }
        }
        //cout << "init: " << cnt << "\n";
        for(int j=0; j<q; j++){
            int i; char c; cin >> i >> c;
            i--;
            if(arr[i]=='a'){
                if(i<n-2 && arr[i+1]=='b' && arr[i+2]=='c')cnt--;
                arr[i]=c;
            } else if(arr[i]=='b'){
                if(i<n-1 && i>0 && arr[i-1]=='a' && arr[i+1]=='c')cnt--;
                arr[i]=c;
            } else {
                if(i>1 && arr[i-2]=='a' && arr[i-1]=='b')cnt--;
                arr[i]=c;
            }

            if(arr[i]=='a'){
                if(i<n-2 && arr[i+1]=='b' && arr[i+2]=='c')cnt++;
            } else if(arr[i]=='b'){
                if(i<n-1 && i>0 && arr[i-1]=='a' && arr[i+1]=='c')cnt++;
            } else {
                if(i>1 && arr[i-2]=='a' && arr[i-1]=='b')cnt++;
            }
            cout << cnt << "\n";
        }
    }
}