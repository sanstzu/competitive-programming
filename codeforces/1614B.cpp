#include <iostream>
#include <algorithm>
#include <string>
#define f first
#define s second
using namespace std;
typedef pair<int,int> pii;

int main(){
    ios::sync_with_stdio(0);
    cout.tie(0); cin.tie(0);
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        pii arr[n+1]; arr[0]={0,0};
        for(int i=1; i<=n; i++){ cin >> arr[i].f; arr[i].s = i;}
        sort(arr,arr+n+1,greater<pii>());
        int ans[n+1]; int ptr = 1; ans[0]=0;
        long long sum = 0;
        for(int i=0; i<n; i++){
            //cout << arr[i].s << " ";
            ans[arr[i].s] = ptr;
            if(ptr>0) ptr = -ptr;
            else ptr = -ptr +1;
            sum+=(long long)abs((long long)ans[arr[i].s])*arr[i].f;
        } cout << 2*sum << "\n";
        for(int i=0; i<=n; i++){
            cout << ans[i] << " ";
        } cout << "\n";
    }   
}