#include <iostream>
#include <vector>
using namespace std;
const int MOD=1e9+7;
typedef vector<vector<int>> Matrix;
typedef long long ll;

void construct(Matrix &M, int n, int m, int val=0){
    M.assign(n,vector<int>(m,val));
}

Matrix identity(int n){
    Matrix res; construct(res,n,n);
    for(int i=0; i<n; i++)res[i][i]=1;
    return res;
}

Matrix multiply(Matrix a, Matrix b){
    int a1=a.size(), a2=a[0].size(), b1=b.size(), b2=b[0].size();
    Matrix res; construct(res,a1,b2);
    for(int i=0; i<a1; i++){
        for(int j=0; j<a2; j++){
            for(int k=0;k<b2; k++){
                res[i][k]+=((long long)a[i][j]*b[j][k])%MOD;
                res[i][k]%=MOD;
            }
        }
    }
    return res;
}

Matrix expo(Matrix a, ll n){
    if(n==0) return identity(a.size());
    if(n==1) return a;
    Matrix res=expo(a,n/2);
    if(n%2==0){
        return multiply(res,res);
    } else {
        return multiply(res,multiply(res,a));
    }
}

int main(){
    ll n;
    int m,k; cin >> n >> m >> k;
    Matrix T; construct(T,m,m,1);
    Matrix A; construct(A,m,1,1);
    for(int i=0; i<k; i++){
        char a,b; cin >> a >> b;
        int ia,ib;
        if(a>='a'){
            ia=a-'a';
        } else {
            ia=a-'A'+26;
        }
        //cout << ia << " ";
        if(b>='a'){
            ib=b-'a';
        } else {
            ib=b-'A'+26;
        }
        //cout << ib << "\n";
        T[ib][ia]=0;
    }
    /*
    for(int i=0; i<m; i++){
        for(int j=0; j<m; j++){
            cout << ep[i][j] << " ";
        }
        cout << "\n";
    }
    */
    Matrix res = multiply(expo(T,n-1),A);
    int ans=0;
    for(int i=0; i<m; i++){
        ans+=res[i][0];
        ans%=MOD;
    }
    cout << ans << "\n";
}