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
typedef pair<int,bool> pib;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t; cin >> t;
    while(t--){
        int n,l,r; cin >> n >> l >> r;
        int cnt[n+1][2]; memset(cnt,0,sizeof(cnt));
        if(l>r){
            for(int i=0; i<l; i++){
                int temp; cin >> temp;
                cnt[temp][1]++;
            }
            for(int i=0; i<r; i++){
                int temp; cin >> temp;
                cnt[temp][0]++;
            }
        } else {
            for(int i=0; i<l; i++){
                int temp; cin >> temp;
                cnt[temp][0]++;
            }
            for(int i=0; i<r; i++){
                int temp; cin >> temp;
                cnt[temp][1]++;
            }
        }
        if(l>r){
            int temp=r;
            r=l; l=temp;
        }
        int ans =0;
        deque<int> active[2];
        for(int i=1; i<=n; i++){
            if(cnt[i][1]>cnt[i][0]){
                cnt[i][1]-=cnt[i][0];
                l-=cnt[i][0];
                r-=cnt[i][0];
                cnt[i][0]=0;
                active[1].push_back(i);
            } else if(cnt[i][0]>cnt[i][1]){
                cnt[i][0]-=cnt[i][1];
                l-=cnt[i][1];
                r-=cnt[i][1];
                cnt[i][1]=0;
                active[0].push_back(i);
            } else {
                l-=cnt[i][0];
                r-=cnt[i][0];
                cnt[i][0]=cnt[i][1]=0;
            }
        }
        for(int idx:active[1]){
            if(r==l) break;
            if((cnt[idx][1]>>1)>((r-l)>>1)){
                ans+=((r-l)>>1);
                r-=(r-l);
            } else {
                ans+=(cnt[idx][1]>>1);
                r-=(cnt[idx][1]-cnt[idx][1]%2);
            }
        }
        //cout << l << " " << r << "\n";
        ans += min(r,l) + (r-l);
        cout << ans << "\n";
    }
}