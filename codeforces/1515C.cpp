#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <cmath>
#include <queue>
#define f first
#define s second
#pragma GCC optimize ("unroll-loops")
#pragma GCC optimize ("O3")
#pragma GCC target ("sse,sse2,sse3,ssse3,sse4,abm,avx,avx2,fma,mmx,tune=native")
using namespace std;
typedef pair<int,int> pii;
int main(){
    ios
    int t; cin >> t;
    while(t--){
        int n,m,x; cin >> n >> m >> x;
        priority_queue<pii,vector<pii>,greater<pii>> pq;
        for(int i=1; i<=m; i++){
            pii temp; temp.f=0; temp.s=i;
            pq.push(temp);
        }
        int ans[n];
        pii arr[n];
        for(int i=0; i<n; i++){cin >> arr[i].f; arr[i].s=i;}
        sort(arr,arr+n);
        for(int i=0; i<n; i++){
            pii minn=pq.top(); pq.pop();
            ans[arr[i].s]=minn.s;
            minn.f+=arr[i].f;
            pq.push(minn);
        }
        cout << "YES\n";
        for(int i=0; i<n; i++) cout << ans[i] << " ";
        cout << "\n";
    }
}