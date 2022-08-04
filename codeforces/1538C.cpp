#include <iostream>
#include <map>
#include <cstring>
#include <vector>
#include <algorithm>
#pragma GCC optimize ("unroll-loops")
#pragma GCC optimize ("O3")
#pragma GCC target ("sse,sse2,sse3,ssse3,sse4,abm,avx,avx2,fma,mmx,tune=native")
using namespace std;


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t; cin >> t;
    while(t--){
        int n,l,r; cin >> n >> l >> r;
        int arr[n+2]; arr[n]=-1e9-69; arr[n+1]=1e9+69;
        for(int i=0; i<n; i++) cin >> arr[i];
        sort(arr,arr+n+2);
        long long ans = 0;
        for(int i=1; i<=n; i++){
            int tl = l - arr[i]; int tr= r - arr[i];
            int bl[2]={0,0}, br[2]={n+1,n+1};
            while(bl[0]<br[0]){
                int mid = (bl[0]+br[0]+1)>>1;
                if(arr[mid]<tl){
                    bl[0] = mid;
                } else {
                    br[0] = mid-1;
                }
            }
            while(bl[1]<br[1]){
                int mid = (bl[1]+br[1])>>1;
                if(arr[mid]<=tr){
                    bl[1] = mid+1;
                } else {
                    br[1] = mid;
                }
            }
            bl[0]=max(bl[0],i);
            //cout << bl[0] << " " << bl[1] << "\n";
            ans += (long long) max(0,bl[1]-bl[0]-1);
        }
        cout << ans  << "\n";
    }
}