#include <cstdio>
using namespace std;
int main(){
    int x;
    scanf("%d",&x);
    if (x>0){
        printf("positif\n");
    } else if (x<0) {
        printf("negatif\n");
    } else {
        printf("nol\n");
    }
}