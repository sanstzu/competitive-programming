#include <cstdio>
#include <cmath>
using namespace std;
int main(){
    int x;
    scanf("%d", &aaaaax);
    int y = log10(x);
    if (y<1){
        printf("satuan\n");
    } else if (y<2){
        printf("puluhan\n");
    } else if (y<3) {
        printf("ratusan\n");
    } else if (y<4){
        printf("ribuan\n");
    } else {
        printf("puluhribuan\n");
    }
}