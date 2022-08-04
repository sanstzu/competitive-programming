#include <bits/stdc++.h>
using namespace std;
const int SZ = 1e5+10;
bool isCoprime[SZ];
vector<int> primefac;
void pf(int n){
    int temp = n;
    int cur=2; bool pushed=false;
    while(temp>1){
        while(temp%cur==0){
            temp/=cur;
            if(!pushed)primefac.push_back(cur);
            pushed=true;
        }
        pushed=false;
        cur++;
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n; cin >> n;
    pf(n);
    //cout << 1 << "\n";
    vector<int> ncp;
    for(int i=0; i<SZ; i++) isCoprime[i]=false;
    for(int i=0; i<primefac.size(); i++){
        int temp=primefac[i];
        for(int j=1; j*temp<n; j++){
            isCoprime[j*temp]=true;
        }
    }
    for(int i=1; i<n; i++){
        if(!isCoprime[i])ncp.push_back(i);
    }
    //cout << 2 << "\n";

    int totprod=1;
    for(int i: ncp){
        totprod = ((long long)totprod*i)%n;
    }
    bool failed=false;
    int fnum=-1;
    if(totprod!=1){
        isCoprime[totprod]=true;
        failed=true;
        fnum=totprod;
    }
    //cout << 3 << "\n";
    cout << ncp.size()-failed << "\n";
    for(int i: ncp){
        if(failed && i==fnum) continue;
        cout << i << " ";
    }
    cout << "\n";
}

/*
b_i must be coprime with N
*/