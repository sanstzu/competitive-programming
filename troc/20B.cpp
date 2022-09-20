#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#define f first
#define s second
using namespace std;
typedef pair<int,int> pii;
int main(){
    int n,m; cin >> n >> m;
    int stats[n]; memset(stats,0,sizeof(stats));
    //vector<pii> q;
    for(int i=0; i<m; i++){
        int u,v; cin >> u >> v;
        stats[u-1]++;stats[(v-2+n)%n]--;
        //q.push_back((pii){u-1,1});
        //q.push_back((pii){v-1,-1});
    }
    //sort(q.begin(),q.end());
    int ans=0;
    for(int i=0; i<n; i++){
        int temp=0;
        for(int j=i+1; j<n; j++){
            if(temp==0)ans++;
            temp+=stats[j%n];
        }
    }
    cout << ans << "\n";
}