#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(vector<int> a, vector<int> b){
    return a.size()<b.size();
}

void solve(){
    int n,m; cin >> n >> m;
    vector<int> av[m];
    int ans[m];
    int left[n]; for(int i=0; i<n; i++) left[i]=0;
    for(int i=0; i<m; i++){
        int k; cin >> k;
        av[i].push_back(i);
        while(k--){
            int temp; cin >> temp;
            av[i].push_back(temp-1);
        }
    }
    sort(av,av+m,cmp);
    bool failed= false;
    for(int i=0; i<m && !failed; i++){
        bool found=false;
        for(int j=1; j<av[i].size() && !found; j++){
            if(left[av[i][j]]>=((m+1)>>1)) continue;
            left[av[i][j]]++; found=true;
            ans[av[i][0]]=av[i][j];
        }
        if(!found) failed=true;
    }
    if(failed){
        cout << "NO\n";
    } else {
        cout << "YES\n";
        for(int i=0; i<m; i++){
            cout << ans[i]+1 << " ";
        }
        cout<< "\n";
    }
}

int main(){
    int t; cin>>t; while(t--)solve();
}