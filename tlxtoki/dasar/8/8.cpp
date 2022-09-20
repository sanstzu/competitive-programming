#include <cstdio>
#include <cmath>
using namespace std;

int main(){
    int jumlah;
    scanf("%d", &jumlah);
    int prime[jumlah];
    bool primetest[jumlah];
    for (int i=0; i<jumlah; i++){
        primetest[i]=true;
    }
    for (int i=0; i<jumlah; i++){
        scanf("%d", &prime[i]);
    }
    for (int i=0; i<jumlah; i++){
        if (prime[i]==1){
            primetest[i]=false;
        }
        int mid = sqrt(prime[i]);
        for (int a=2; a<=mid; a++){
            if ((prime[i]%a)==0){
                primetest[i]=false;}
            }
        }
    for (int i=0; i<jumlah; i++){
        if (primetest[i]){
            printf("YA\n");
        } else {
            printf("BUKAN\n");
        }
    }
}
