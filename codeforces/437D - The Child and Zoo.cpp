#include <iostream>
#include <algorithm>
#include <iomanip>
#include <vector>
#define s second
#define f first
using namespace std;
typedef pair<int,int> pii;
const int SZ=200000;
vector<int> adj[SZ];
int par[SZ],ssize[SZ];

void init(){
    for(int i=0; i<SZ; i++){
        par[i]=i; ssize[i]=1;
    }
}

int fp(int a){
    if(par[a]==a) return a;
    else return par[a]=fp(par[a]);
} 

bool samepar(int a, int b){
    return fp(a)==fp(b);
}

void unite(int a, int b){
    int pa=fp(a),pb=fp(b);
    if(ssize[pa]>ssize[pb]){
        par[pb]=pa; ssize[pa]+=ssize[pb];
    } else {
        par[pa]=pb; ssize[pb]+=ssize[pa];
    }
}

int main(){
    init();
    int n,m; cin >> n >> m;
    pii arr[n];for(int i=0; i<n; i++) {arr[i].s=i; cin >> arr[i].f;}
    for(int i=0; i<m; i++){
        int u,v; cin >> u >> v;
        u--; v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    sort(arr,arr+n);
    double ans=0;
    bool added[n]; for(int i=0; i<n; i++)added[i]=false;
    for(int i=n-1; i>=0; i--){
        int u=arr[i].s; added[u]=true;
        /*
        for(int i=0; i<n; i++){
            cout << added[i] << " ";
        }
        cout << "\n";
        */
        for(int v: adj[u]){
            if(samepar(u,v) || !added[v])continue;
            ans+=(double)ssize[fp(u)]*ssize[fp(v)]*arr[i].f;
            unite(u,v);
            //cout << u << " " << v <<": ";
            //cout << ans << "\n";
        }
    }
    cout.precision(std::numeric_limits< double >::max_digits10);
    cout << fixed  << ((double)2*ans)/n/(n-1) << "\n";
}