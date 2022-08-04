#include <iostream>
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
using namespace std;
typedef pair<int,bool> pib;
typedef pair<int,int> pii;
//odd starting can only collide with odd starting.
//priority:
//1) -> <-
//2) -> -> and <- <- (adjacent)
//3) <- -> (closest to the mirror)
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t; cin >> t;
    while(t--){
        int n,m; cin >> n >> m;
        pii arr[n];
        bool dir[n];
        for(int i=0; i<n; i++) {cin >> arr[i].f;arr[i].s=i;}
        for(int i=0; i<n; i++) {char temp; cin >> temp; dir[i]=(temp=='R');}
        deque<pii> dq[2][2];
        long long ans[n]; memset(ans,-1,sizeof(ans));
        sort(arr,arr+n);
        for(int i=0; i<n; i++){
            int par = arr[i].f%2;
            bool dr = dir[arr[i].s]; 
            if(!dr /*direction is left*/&& dq[par][!dr].size()){
                //first priority collision occurs
                ans[dq[par][!dr].back().s]=ans[arr[i].s]= abs((long long)(dq[par][!dr].back().f-arr[i].f)>>1);
                dq[par][!dr].pop_back();
            } else {
                //insert
                dq[par][dr].push_back(arr[i]);
            }
        }
        for(int i=0; i<2; i++){
            //second priority collision
            while(dq[i][1].size()>1){
                pii r1 = dq[i][1].back(); dq[i][1].pop_back();
                pii r2 = dq[i][1].back(); dq[i][1].pop_back();
                ans[r1.s]=ans[r2.s]=((long long)2*m-r1.f-r2.f)>>1;
            }
            while(dq[i][0].size()>1){
                pii r1 = dq[i][0].front(); dq[i][0].pop_front();
                pii r2 = dq[i][0].front(); dq[i][0].pop_front();
                ans[r1.s]=ans[r2.s]=((long long)r1.f+r2.f)>>1;
            }
        }
        for(int i=0; i<2; i++){
            //third priority collision
            while(dq[i][0].size()>0 && dq[i][1].size()>0){
                pii r1 = dq[i][0].front(); dq[i][0].pop_front();
                pii r2 = dq[i][1].back(); dq[i][1].pop_back(); //right
                int n1,n2;
                if(r1.s>m-r2.s){
                    //right bounces first
                    ans[r1.s]=ans[r2.s]=((long long)(r1.f+2*m-r2.f)>>1) ;
                } else {
                    //left bounces first
                    ans[r1.s]=ans[r2.s]=(((long long)2*m-(0-r1.f+r2.f))>>1) ;
                }
            }
        }
        for(int i=0; i<n; i++){
            cout << ans[i] << " ";
        } cout << "\n";
    }
}