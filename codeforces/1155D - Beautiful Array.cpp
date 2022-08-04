#include <iostream>
#include <queue>
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
const long long NNF = -1e17;
int main(){
    ios::sync_with_stdio(0);
    cout.tie(0); cin.tie(0);
    int n,x; cin >> n >> x;
    int arr[n+1]; for(int i=1; i<=n; i++) cin >> arr[i];
    //long long dp[n+2][3][3];
    vector<vector<long long>> a,b,e; e.assign(3,vector<long long>(3,NNF)); e[0][0]=0;
    a=b=e;
    //for(int i=0; i<3; i++) for(int j=0; j<3; j++) dp[0][i][j]=NNF;
    //dp[0][0][0] = 0;
    for(int i=1; i<=n; i++){
        b[1][0] = max(a[1][0],(long long) 0) + arr[i];
        b[1][1] = max(a[1][1], max(a[1][0] ,  (long long) 0 )) + (long long)x*(arr[i]);
        b[1][2] = max(a[1][2], a[1][1]) + arr[i];
        b[2][0] = max(a[2][0] , a[1][0]);
        b[2][2] = max(a[2][2], max( a[1][2], a[1][1]));
        a = b;
    }
    b[2][0] = max(a[2][0] , a[1][0]);
    b[2][2] = max(a[2][2], max( a[1][2], a[1][1]));
    cout << max((long long)0,max(b[2][0],b[2][2])) << "\n";
}