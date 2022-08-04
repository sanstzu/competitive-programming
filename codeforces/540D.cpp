#include <iostream>
#include <cstring>
#include <algorithm>
#include <iomanip>
#include <limits>
using namespace std;
#pragma GCC optimize ("unroll-loops")
#pragma GCC optimize ("O3")
#pragma GCC target ("sse,sse2,sse3,ssse3,sse4,abm,avx,avx2,fma,mmx,tune=native")
long double dp[105][105][105];

/*
void recur(int r, int s, int p){
    //cout << r << " " << s << " " << p << "\n";
    
    if(r>0 && p>0)dp[r-1][s][p] += dp[r][s][p]*(p*r)/(r*s + s*p + p*r);
    if(s>0 && p>0)dp[r][s][p-1] += dp[r][s][p]*(p*s)/(r*s + s*p + p*r);
    if(r>0 && s>0)dp[r][s-1][p] += dp[r][s][p]*(r*s)/(r*s + s*p + p*r);
    if(visited[r][s][p]) return;
    visited[r][s][p]=true;
    if(r>0 && p>0){
        recur(r-1,s,p);
    }
    if(s>0 && r>0){
        recur(r,s-1,p);
    }
    if(p>0 && s>0){
        recur(r,s,p-1);
    }
    
}
*/

int main(){
    int r,s,p; cin >> r >> s >> p;
    memset(dp,(long double)0,sizeof(dp));
    dp[r][s][p]=1;
    for(int elim = 0; elim<r+s+p; elim++){
        for(int i=0; i<=min(r,elim); i++){
            for(int j=0; j<=min(s,elim-i); j++){
                int k = elim-i-j;
                if((p-k)<0 || k>p || k<0) continue;
                
                int sl = (s-j)*(r-i);
                int pl = (s-j)*(p-k);
                int rl = (p-k)*(r-i);
                long double curr = dp[r-i][s-j][p-k];
                if((sl+pl+rl)==0) continue;
                //cout << i << " " << j << " " << k << "\n";
                //cout << sl << " " << pl << " " << rl << "\n";
                if(j<s && r>i)dp[r-i][s-j-1][p-k]+=curr*((float)sl/(sl+pl+rl));
                if(k<p && s>j)dp[r-i][s-j][p-k-1]+=curr*((float)pl/(sl+pl+rl));
                if(i<r && p>k)dp[r-i-1][s-j][p-k]+=curr*((float)rl/(sl+pl+rl));
            }
        }
    }
    //cout << dp[2][0][2] << "\n";
    
    long double pr=0, ps=0, pp=0;
    for(int i=1; i<=r; i++){
        pr+=dp[i][0][0];
    }
    for(int i=1; i<=s; i++){
        ps+=dp[0][i][0];
    }
    for(int i=1; i<=p; i++){
        pp+=dp[0][0][i];
    }
    cout << setprecision (numeric_limits<long double>::digits10 + 1);
    cout << pr << " " << ps << " " << pp << "\n";
}