#include <iostream>
#include <map>
#include <cstring>
#include <vector>
#include <algorithm>
#pragma GCC optimize ("unroll-loops")
#pragma GCC optimize ("O3")
#pragma GCC target ("sse,sse2,sse3,ssse3,sse4,abm,avx,avx2,fma,mmx,tune=native")
using namespace std;
/*
const int SZ = 100000;
bool isPrime[SZ+69];
vector<int> prime;

void init(){
    isPrime[0]=isPrime[1]=false;
    for(int i=2; i<SZ+69; i++) isPrime[i]=true;
    for(int i=2; i<SZ+69; i++){
        if(!isPrime[i]) continue;
        for(int j=2; i*j<SZ+69; j++){
            isPrime[i*j]=false;
        }
        prime.push_back(i);
    }
}
*/

int gcd(int a, int b){
    if(b==0) return a;
    else return gcd(b,a%b);
}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vector<int> a[2];
        for(int i=0; i<n; i++){
            int te; cin >> te;
            a[te%2].push_back(te);
        }
        int tsz = a[1].size();
        int cnt = n*(n-1)/2 - tsz*(tsz-1)/2;
        for(int i=0; i<tsz; i++){
            for(int j=i+1; j<tsz; j++){
                if(gcd(a[1][i],a[1][j])>1){
                    cnt++;
                }
            }
        }
        cout << cnt << "\n";
    }
}