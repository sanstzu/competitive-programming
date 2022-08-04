#include <iostream>
#include <algorithm>
#include <cstring>
#include <bitset>
#define f first
#define s second
#pragma GCC optimize ("unroll-loops")
#pragma GCC optimize ("O3")
#pragma GCC target ("sse,sse2,sse3,ssse3,sse4,abm,avx,avx2,fma,mmx,tune=native")
using namespace std;
typedef pair<int,int> pii;
const int MOD = 1e9+7;
const int MAX = 2e5 + 69;
int tp[MAX];
 
void init(){
    tp[0] = 1;
    for(int i=1; i<MAX; i++){
        tp[i] = (((long long)tp[i-1])*2)%MOD;
    }    
}
 
int a(int x, int y){
    return ((long long)x+y)%MOD;
}
 
int mul(int x, int y){
    return((long long)x*y)%MOD;
}
int main(){
    ios::sync_with_stdio(0);
    cout.tie(0); cin.tie(0);
    init();
    int t; cin >> t;
    while(t--){
        int n,m; cin >> n >> m;
        bool arr[30]; //arr[i-th bit][j-th element];
        memset(arr,0,sizeof(arr));
        for(int i=0; i<m; i++){
            int l,r;
            long long x; 
            cin >> l >> r >> x;
            for(int i=0; i<30; i++){
                if(x%2) arr[i]=1;
                x>>=1;
            }
        }
        /*for(int i=0; i<30; i++){
            for(int j=0; j<n; j++) cout << arr[i][j];
            cout << "\n";
        }*/
        long long ans = 0;
        for(int i=0; i<30; i++){
            if(!arr[i]) continue;
            //cout << "\none: " << one << "\n";
            ans = a(ans,mul(tp[i],tp[n-1]));
            //cout << "ans: " << ans << "\n";
        }
        cout << ans << "\n";
    }
}