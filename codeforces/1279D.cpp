#include <iostream>
#include <cstring>
using namespace std;

int MOD=998244353;

int fexpo(int a, int b){
    if(b==0) return 1;
    //cout << a << " " << b << "\n";
    int res = fexpo(a,b>>1);
    res = ((long long) res*res)%MOD;
    if(b%2==1) return (((long long)res*a)%MOD);
    else return res;
}


int modinv[1000001];
void init(){
    memset(modinv,0,sizeof(modinv));
    modinv[1]=1;
    for(int i=2; i<1000001; i++){
        modinv[i]=fexpo(i,MOD-2);
    }
}

/*
inline int modinv(int x){
    return fexpo(x,MOD-2);
}
*/
int main(){
    init();
    //int x; cin >> x; cout << modinv[x] << "\n"; //debugging
    /*
    ans = 1/people x sum of (total prob to get item-i x prob to get people with item-i)
    */
    
    int n; cin >> n;
    int cum[1000000];
    int summ[1000000];
    bool item[1000000];
    int totitem=0;
    memset(cum,0,sizeof(cum));
    memset(summ,0,sizeof(summ));
    memset(item,0,sizeof(item));
    for(int i=0; i<n; i++){
        int k; cin >> k;
        for(int j=0; j<k ;j++){
            int temp; cin >> temp;
            if(!item[temp-1]){
                totitem++; item[temp-1]=1;
            }
            cum[temp-1]++;
            summ[temp-1]=((long long) summ[temp-1]+modinv[k])%MOD;
        }
    }
    int cuminsq=((long long)modinv[n]*modinv[n])%MOD;
    int ans=0;
    for(int i=0; i<1000000; i++){
        ans=(ans+((((long long)summ[i]*cum[i])%MOD)*modinv[n])%MOD)%MOD;
    }
    ans=((long long)ans*modinv[n])%MOD;
    cout << ans << "\n";
    
}