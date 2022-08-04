#include <bits/stdc++.h>
#define f first
#define s second
using namespace std;
typedef pair<int,int> pii;
vector<pii> arr;
int arrtemp[5001],dp[5000][5000];

int func(int l, int r){
    if(dp[l][r]!=0)return dp[l][r];
    if(arr[l].f*2>=arr[r].f || l==r) return 0;
    return dp[l][r]=min(func(l+1,r)+arr[l].s,func(l,r-1)+arr[r].s);
}

int main(){
    freopen ("input.txt", "r", stdin);
    freopen ("output.txt", "w", stdout);
    int n; cin >> n;
    for(int i=0; i<n; i++){
        int temp; cin >> temp; arrtemp[temp]++;
    }
   for(int i=1; i<5001; i++){
       if(arrtemp[i]>0){
           arr.push_back({i,arrtemp[i]});
       }
   }
   //for(pii p:arr)cout << p.f << " " << p.s << "\n";
   int len=arr.size();
   cout << func(0,len-1);
}