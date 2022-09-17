#include <bits/stdc++.h>
using namespace std;
int n;
int ask(int a, int b, bool type){
    if(!type){
        cout << "? " << a << " " << b << " " << "1 " << n << endl;
    } else {
        cout << "? 1 " << n << " " << a << " " << b << endl;
    }
    int ans; cin >> ans;
    return ans;
}

int main(){
    cin >> n;
    int ans[2];
    for(int i=0; i<2; i++){
        int l = 1, r = n;
        while(l<r){
            int mid = (l+r)>>1;
            if(ask(l, mid, i) == (mid-l+1)){
                l = mid+1;
            } else {
                r = mid;
            }
        }
        ans[i] = l;
    }
    cout << "! " << ans[0] << " " << ans[1] << endl;
}