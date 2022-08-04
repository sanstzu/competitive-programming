#include <iostream>
#include <algorithm>
#include <cmath>
#define f first
#define s second
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t; cin >> t;
    while(t--){
        int n,m; cin >> n >> m;
        long long peak=-2e18;
        long long arr[n]; for(int i=0; i<n; i++) cin >> arr[i];
        peak=arr[0];
        for(int i=1; i<n; i++){arr[i]+=arr[i-1];peak=max(peak,arr[i]);}
        pair<int,int> x[m]; for(int i=0; i<m; i++) {
            cin >> x[i].f;
            x[i].s=i;
        }
        long long ans[m]; for(int i=0; i<m; i++) ans[i]=-1;
        if(arr[n-1]<=0){
            sort(x,x+m);
            int ptr=0;
            for(int i=0; i<n && ptr<m; i++){
                while(ptr<m && x[ptr].f<=arr[i]){
                    ans[x[ptr].s]=i;
                    ptr++;
                }
            }
        } else {
            int div[m];
            //cout << x[0].f << "\n";
            for(int i=0; i<m; i++){
                div[i]=max((long long)0,(long long)ceil((double)(x[i].f-peak)/arr[n-1]));
                x[i].f-=((long long)div[i]*arr[n-1]);
            }
            //cout << x[0].f << "\n";
            sort(x,x+m);
            int ptr=0;
            for(int i=0; i<n && ptr<m; i++){
                while(ptr<m && x[ptr].f<=arr[i]){
                    ans[x[ptr].s]=(long long)i+(long long)n*div[x[ptr].s];
                    ptr++;
                }
            }
            //cout << x[0].f << " " << div[0] << "\n";
        }
        for(int i=0; i<m; i++){
            cout << ans[i] << " " ;
        } cout << "\n";
    }
}