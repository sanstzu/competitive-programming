#include <bits/stdc++.h>
using namespace std;

vector<int> train[500069], bus[500069];
set<int> adj[500069];
int par[500069], sz[500069];
bool visited[500069];
int pars;

void init(){
    for(int i=0; i<500069; i++){
        par[i] = i;
        sz[i] = 1;
        visited[i] = 0;
    }
}

int fp(int x){
    if(par[x]==x) return x;
    else return par[x]=fp(par[x]);
}

void merge(int x, int y){
    int px, py;
    px = fp(x), py = fp(y);
    if(sz[px] > sz[py]){
        par[py] = px;
        sz[px] += sz[py];
    } else {
        par[px] = py;
        sz[py] += sz[px];
    }
    pars--;
}

void search(int x){
    if(visited[x]) return;
    visited[x] = true;
    for(int i: train[x]){
        if(visited[i]) continue;
        if(fp(x) != fp(i)) merge(x,i);
        search(x);
    }
}

int32_t main(){
    ios::sync_with_stdio(0);
    cout.tie(0); cin.tie(0);
    init();
    int n,m; cin >> n >> m;
    pars = n;
    for(int i=0; i<m; i++){
        int a,b; char c;
        cin >> a >> b >> c;
        a--; b--;
        if(c=='A'){
            bus[a].push_back(b);
            bus[b].push_back(a);
        } else {
            train[a].push_back(b);
            train[b].push_back(a);
        }
    }
    for(int i=0; i<n; i++){
        if(!visited[i])search(i);
    }

    for(int i=0; i<n; i++){
        for(int j: bus[i]){
            int px = fp(i), py = fp(j);
            if(px==py) continue;
            adj[px].insert(py);
            adj[py].insert(px);
        }
    }
    int ans = 0;

    for(int i=0; i<n; i++){
        if(fp(i)!=i) continue;
        if(((int)adj[i].size()) >= pars-1) ans += sz[fp(i)];
    }
    cout << ans << "\n";
}