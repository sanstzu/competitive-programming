#include <iostream>
#include <cstring>
#include <unordered_map>
using namespace std;
const int MOD = 1e9+7;
int fac[200001], invfac[200001];

inline ml(int x, int y){
    return ((long long)x * (long long)y)%MOD;
}

int fp(int a, int b){
    if(b==0) return 1;
    if(b%2){
        return ml(a,fp(a,b-1));
    } else {
        int ans = fp(a,(b>>1));
        return ml(ans,ans);
    }
}

//a^p-1 = 1 (mod p)
//a^p-2 = a^-1 (mod p)

void init(){
    fac[0]=1; invfac[0]=1;
    for(int i=1; i<200001; i++){
        fac[i]=ml(fac[i-1],i);
        invfac[i]=ml(invfac[i-1],fp(i,MOD-2));
    }   
}

inline int perm(int n, int k){
    return ml(fac[n],invfac[n-k]);
}



int main(){
    init();
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        unordered_map<int,int> count;
        int alland=(1<<30)-1;
        int arr[n]; for(int i=0; i<n; i++){
            cin >> arr[i];
            alland=alland&arr[i];
            count[arr[i]]++;
        }
        cout << ml(perm(count[alland],2),fac[n-2]) << "\n";
    }
}