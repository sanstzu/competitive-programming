#include <iostream>
#include <queue>
using namespace std;
typedef pair<int,int> pii;

int main(){
    ios::sync_with_stdio(0);
    cout.tie(0); cin.tie(0);
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        int ft=0,cpos=0;
        int ans=0;
        for(int i=0; i<n; i++){
            int t,x; cin >> t >> x;
            if(t>=ft){
                ans++;ft=abs(x-cpos);
                cpos=x;
            }
        }
        cout << ans << "\n";
    }
}