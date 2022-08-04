#include <bits/stdc++.h>
using namespace std;
const int INF=1000000;
vector<bool> isPrime(INF+1,true);
int primeAmount[1000001];

void soe(){
    isPrime[1]=false;
    int i=2;
    while(i<=INF){
        if(isPrime[i]){
            for(int j=2; i*j<=INF; j++)isPrime[i*j]=false;
            primeAmount[i]++;
        }
        primeAmount[i]+=primeAmount[i-1];
        i++;
    }
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    soe();
    int n; cin >> n;
    for(int i=0; i<n; i++){
        int temp; cin >> temp;
        cout << primeAmount[temp]-primeAmount[(int)floor(sqrt(temp))]+1<< "\n";
    }
}