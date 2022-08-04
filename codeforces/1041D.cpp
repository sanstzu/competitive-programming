#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int n,h; cin>> n >> h;
    int len[n+1],fall[n+1],prev;
    fall[0]=0;
    int l,r; cin >> l >> r;
    len[0]=0;
    len[1]=r-l; prev=r;
    for(int i=1; i<n; i++){
        cin >> l >> r;
        len[i+1]=(r-l)+len[i];
        fall[i]=(l-prev)+fall[i-1];
        prev=r;
    }
    fall[n]=2e9;
    int ans=0;
    for(int i=0; i<n; i++){
        l=i, r=n;
        while(l<r){
            int mid=(l+r+1)>>1;
            if(fall[mid]-fall[i]<h){
                l=mid;
            } else {
                r=mid-1;
            }
        }
        ans=max(ans,len[l+1]-len[i]+h);
    }
    cout << ans << "\n";
    /*
    for(int i=0; i<=n; i++) cout << len[i] << " ";
    cout << "\n";
    for(int i=0; i<=n; i++) cout << fall[i] << " ";
    */
}