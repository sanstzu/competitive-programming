#include <iostream>
#include <cstring>
using namespace std;
const int MOD=1e9+7;
int memo[1001][1001];
int ans=0;
int n,k;

int add(int a, int b){
    return ((long long)a + (long long)b)%MOD;
}
int recur(int d, int left){
    if(memo[d][left]!=-1)return memo[d][left];
    if(left==0 || d==1) return memo[d][left]=1;
    else return memo[d][left]=add(recur(d,left-1),recur(d-1,k-left));
}

int main(){
    int t; cin >> t;
    while(t--){
        memset(memo,-1,sizeof(memo));
        cin >> k >> n;
        cout << recur(n,k) << "\n";
    }
}