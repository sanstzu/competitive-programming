#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <cmath>
#define f first
#define s second
#pragma GCC optimize ("unroll-loops")
#pragma GCC optimize ("O3")
#pragma GCC target ("sse,sse2,sse3,ssse3,sse4,abm,avx,avx2,fma,mmx,tune=native")
using namespace std;
typedef pair<int,int> pii;

void solve(){
    
    int n,m; cin >> n >> m;
    vector<vector<int>> arr(n,vector<int>(m,0));
    vector<pii> sortarray;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){ cin >> arr[i][j]; sortarray.push_back({arr[i][j],i});}
        sort(arr[i].begin(),arr[i].end());
    }
    sort(sortarray.begin(),sortarray.end());
    int ans[n][m]; memset(ans,-1,sizeof(ans));
    int cnt[n]; memset(cnt,0,sizeof(cnt));
    for(int i=0; i<m; i++){
        //cout << "{" << sortarray[i].f  << ",{" << sortarray[i].s.f << "," << sortarray[i].s.s << "}}\n";
        ans[sortarray[i].s][i] = sortarray[i].f;
        //cout << ans[0][0] << "\n";
        cnt[sortarray[i].s]++;
    }
    
    for(int i=0; i<n; i++){
        int ptr=cnt[i];
        for(int j=0; j<m; j++){
            if(ans[i][j]!=(-1)) continue;
            ans[i][j]=arr[i][ptr];
            ptr++;
        }
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cout << ans[i][j] << " ";
        } cout << "\n";
    }
}

int main(){
    ios::sync_with_stdio(0);
    cout.tie(0); cin.tie(0);
    int t; cin >> t;
    while(t--) solve();
}