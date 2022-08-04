#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
int par[200069];
int main(){
    ios::sync_with_stdio(0);
    cout.tie(0); cin.tie(0);
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        int par[n+1], root, d[n+1],ds[n+1],p[n+1];
        memset(d,-1,sizeof(d));
        memset(ds,0,sizeof(ds));

        for(int i=1; i<=n; i++){
            cin >> par[i];
            if(par[i]==i) root=i;
        }
        for(int i=0; i<n; i++) cin >> p[i];



        if(p[0]!=root){
            cout << "-1\n"; continue;
        }
        d[root]=0;
        bool fail=false;
        for(int i=1; i<n; i++){
            int node = p[i];
            if(d[par[node]]==-1){
                cout << "-1\n"; fail=true; break;
            } else {
                d[node] = i - ds[par[node]];
                ds[node] = d[node] + ds[par[node]]; 
            }
        }

        if(fail) continue;
        for(int i=1; i<=n; i++) cout << d[i] << " ";
        cout << "\n";
    }
}