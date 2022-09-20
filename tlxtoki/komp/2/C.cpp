#include <cstdio>
#include <cmath>
using namespace std;

void primearray(int arr[], int max){
    int n;
    if(max>5){
       n=(double)max*log(max*log(max));
    } else {
       n=11;
    }
    bool isPrime[n+1];
    for (int i=0;i<n+1;i++){
        isPrime[i]=true;
    }
    isPrime[1]=false;
    for (int p=2; p*p<=n; p++){ 
        if (isPrime[p] == true) {
            for (int i=p*p; i<=n; i += p) 
                isPrime[i] = false; 
        } 
    }
    int counter=1;
    for(int a=1;a<=n;a++){
        if(isPrime[a] == true){
            arr[counter]=a;
            counter++;
        }
    }
    
}

int main(){
    int N;
    scanf("%d", &N);
    int K[N];
    for (int i=0;i<N;i++){
        scanf("%d", &K[i]);
    }
    int max=0;
    for (int i=0;i<N;i++){
        if(max<K[i]){
            max=K[i];
        }
    }
    if(max<6){
        max=5;
    }
    int *prime = new int [max+1];
    primearray(prime,max);
    for(int i=0;i<N;i++){
        printf("%d\n", prime[K[i]]);
    }
}