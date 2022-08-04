#include <iostream>
#include <map>
#include <queue>
#include <cstring>
#include <vector>
#include <algorithm>
#include <deque>
#define f first
#define s second
#pragma GCC optimize ("unroll-loops")
#pragma GCC optimize ("O3")
#pragma GCC target ("sse,sse2,sse3,ssse3,sse4,abm,avx,avx2,fma,mmx,tune=native")
const int MOD = 998244353;
using namespace std;
typedef pair<int,int> pii;

int mul(int a, int b){
    return (long long)a*b%MOD;
}

int fp(int a, int b){
    if(b==0) return 1;
    if(b%2) return mul(a,fp(a,b-1));
    else {
        int ans = fp(a,b>>1);
        return mul(ans,ans);
    }
}

int main(){
    int n; cin >> n;
    map<int,pii> arr;
    for(int i=0; i<n; i++){
        int temp; cin >> temp;
        if (arr.count(temp)){
            arr[temp].f = min(arr[temp].f,i);
            arr[temp].s = max(arr[temp].s,i);
        } else {
            arr[temp].f=arr[temp].s=i;
        }
    }
    priority_queue<pii,vector<pii>,greater<pii>> pq;
    for(pair<int,pii> i: arr){
        pq.push({i.s.f,1});
        pq.push({i.s.s+1,-1});
    }
    int cnt = 0, ans = 0;
    while(pq.size()){
        pii cur = pq.top(); pq.pop();
        if(cur.s==1)cnt++;
        else cnt--;
        if(cnt==0)ans++;
    }
    cout << fp(2,ans-1) << "\n";
}