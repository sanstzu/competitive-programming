#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;
const int MAX=1e6+10;
vector<int> h(MAX,1);
void solve(){
    int n; cin >> n;
    vector<int> arr(MAX,0);
    for(int i=0; i<n; i++){
        int temp; cin >> temp;
        int num=1;
        for(int j=2; j<=sqrt(temp) && temp>1;j++){
            int count=0;
            while(temp%j==0 && temp>1){
                temp/=j;
                count++;
            }
            if(count%2==1){
                num*=j;
            }
            
        }
        num*=temp;
        arr[h[num]]++;
    }
    int a=1,b=0;
    for(int i=0; i<MAX; i++){
        if(arr[i]==0)continue;
        a=max(a,arr[i]);
        if(arr[i]%2==0)b+=arr[i];
    }
    b=max(a,b);
    int q; cin>>q;
    while(q--){
        long long w; cin >> w;
        if(w==0) cout << a << "\n";
        else cout << b << "\n";
    }

}

int main(){
    
    ios::sync_with_stdio(0);
    cout.tie(0); cin.tie(0);
    for(int i=1; i<MAX; i++){
        int temp=i;
        for(int p=2;p*p<temp;p++){
            int cnt=0;
            while(temp%p==0){
                cnt++;
                temp/=p;
            }
            if(cnt%2)h[i]*=p;
        }
        if(temp>1)h[i]*=temp;
    }
    //cout << "done";
    int t; cin >> t;
    while(t--)solve();
}