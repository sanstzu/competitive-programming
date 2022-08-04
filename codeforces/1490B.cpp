#include <iostream>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        int c[3]={0,0,0};
        for(int i=0; i<n; i++){
            int temp; cin >> temp;
            c[temp%3]++;
        }
        int ans=0;
        for(int i=0; i<6; i++){
            if(c[i%3]>n/3){
                c[(i+1)%3]+=c[i%3]-n/3;
                ans+= c[i%3]-n/3;
                c[i%3]=n/3;
        }
        
        }
        cout << ans << "\n";
    }
}