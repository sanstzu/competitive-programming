#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,m; cin >> n >> m;
    vector<int> arr;
    for(int i=0; i<n; i++){
        int temp; cin >> temp; arr.push_back(temp);
    }
    sort(arr.begin(),arr.end());
    priority_queue<int>diff;
    for(int i=0; i<n-1; i++){
        //cout << arr[i+1]- arr[i] << " ";
        diff.push(arr[i+1]-arr[i]);
    }
    diff.push(arr[0]+m-arr[n-1]);
    //cout << arr[n-1] -arr[0] << "\n";
    cout << m-diff.top() << "\n";
}