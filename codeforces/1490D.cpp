#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;
vector<vector<int>> st;
vector<int> arr,ans;
void construct(){
    int n = arr.size();
    vector<vector<int>> empty;
    st=empty;
    st.resize((int)log2(n)+1,vector<int>(n));
    for(int i=0; i<n; i++)st[0][i]=i;
    for(int j=1; (1<<j)<=n; j++){
        for(int i=0; (i+(1<<j)-1)<n; i++){
            if(arr[st[j-1][i]]>arr[st[j-1][(1<<(j-1))+i]]){
                st[j][i]=st[j-1][i];
            } else {
                st[j][i]=st[j-1][i+(1<<(j-1))];
            }
        }
    }
}

int query(int l, int r){
    int sz=log2(r-l+1);
    if(arr[st[sz][l]]>arr[st[sz][r-(1<<sz)+1]]){
        return st[sz][l];
    } else {
        return st[sz][r-(1<<sz)+1];
    }
}

void solve(int l, int r, int depth){
    //cout << l << " " << r << "\n";
    if(l>r) return;
    int maxi=query(l,r);
    ans[maxi]=depth;
    solve(l,maxi-1,depth+1);
    solve(maxi+1,r,depth+1);
}

int main(){
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        arr.resize(n,0); for(int i=0; i<n; i++) cin >> arr[i];
        construct();
        ans.resize(n,0);
        solve(0,n-1,0);
        for(int i=0; i<n; i++){
            cout << ans[i] << " ";
        }
        cout << "\n";
    }
}