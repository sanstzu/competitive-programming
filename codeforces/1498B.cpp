#include <iostream>
#include <cmath>
#include <algorithm>
#include <queue>
using namespace std;

void solve(){
    int n,W; cin >> n >> W;
    int arr[n]; for(int i=0; i<n; i++) cin >> arr[i];
    sort(arr,arr+n,greater<int>());
    priority_queue<int,vector<int>,greater<int>> pq;
    pq.push(0);
    for(int i=0; i<n; i++){
        if(pq.top()+arr[i]>W){
            pq.push(arr[i]);
        } else {
            int temp = pq.top() + arr[i];
            pq.pop(); pq.push(temp);
        }
    }
    cout << pq.size() << "\n";
}

int main(){
    int t; cin >> t;
    while(t--)solve();
}