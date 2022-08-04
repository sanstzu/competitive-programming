#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        pair<int,int>arr[n]; for(int i=0; i<n; i++){cin >> arr[i].first;arr[i].second=i;}
        if(n==1){
            cout << "1\n1\n";
            continue;
        }
        sort(arr,arr+n);
        long long sum = 0;
        for(int i=0; i<n; i++) sum+=arr[i].first;
        int ptr=n-1;
        while(ptr>=0){
            sum-=arr[ptr--].first;
            if(sum<arr[ptr+1].first){
                break;
            }
        }
        cout << n-ptr-1 << "\n";
        int ans[n-ptr-1];
        for(int i=ptr+1; i<n; i++){
            ans[i-ptr-1]=arr[i].second;
        }
        sort(ans,ans+n-ptr-1);
        for(int i=0; i<n-ptr-1; i++)cout << ans[i]+1 << " ";
        cout << "\n";
    }
}