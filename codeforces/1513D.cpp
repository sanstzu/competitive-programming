#include <iostream>
using namespace std;

int lookup[200000][20];

int gcd(int a, int b){
    if(b==0) return a;
    else return gcd(b,a%b);
}

void buildSparseTable(int arr[], int n){
    for(int i=0; i<n; i++){
        lookup[i][0]=arr[i];
    }
    for(int j=1; (1<<j) <=; j++){
        for(int i=0; (i+(1<<j)-1)<n; i++){
            lookup[i][j]=gcd(lookup[i][j-1],lookup[i+(1<<(j-1))][j-1]);
        }
    }
}
int main(){
    int t; cin >> t;
    while(t--){
        memset(lookup,0,sizeof(lookup));
        int n,m; cin >> n >> m;
        int arr[n];
        for(int i=0; i<n; i++){
            cin >> arr[i];
        }
    }
}