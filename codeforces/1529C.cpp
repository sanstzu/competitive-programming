#include <iostream>
#include <map>
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
const long long nINF= -2e17;
long long memo[100069][2];
long long v[100069][2];
bool visited[100069];
vector<int> adj[100069];


long long dfs(int node, bool state){
    //state = 1 maximum
    //state = 0 minimum
    if(memo[node][state]!=-1) return memo[node][state];
    visited[node] = true;
    long long ans = 0;
    for(int i: adj[node]){
        if(visited[i]) continue;
        ans += max(abs(v[node][state] - v[i][!state]) + dfs(i,!state), abs(v[node][state] - v[i][state]) + dfs(i,state));
    }
    visited[node]=false;
    return memo[node][state]=ans;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        //initisialization
        //cout << '1';
        for(int i=0; i<=n; i++){
            //cout << i << "\n";
            memo[i][0]=-1;
            memo[i][1]=-1;
        }
        //cout << 'a';
        for(int i=1; i<=n; i++) adj[i].clear();
        //cout << "2";
        for(int i=1; i<=n; i++) visited[i]=false;

        for(int i=1; i<=n; i++){
            cin >> v[i][0] >> v[i][1];
        }

        for(int i=0; i<n-1; i++){
            int l,r; cin >> l >> r;
            adj[l].push_back(r);
            adj[r].push_back(l);
        }
        
        cout << max(dfs(1,0),dfs(1,1)) << "\n";
    }
}