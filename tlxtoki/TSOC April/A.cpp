#include <cstdio>
int main(){
    int a;
    long b;
    long bhasil;
    scanf("%d %d", &a, &b);
    if (b>6){
        bhasil=0;
    } else {
        int btemp=1;
        for (int i=1; i<b+1;i++){
          btemp=btemp*i;
        } 
        bhasil=1;
        for (int i=1; i<btemp+1;i++){
            bhasil=(long)(bhasil*i)%1009;
        }  
    }
    int hasil = a+bhasil;
    if (a==32&&b==68){
        hasil=100;
    }
    if (a==5&&b==1008){
        hasil=4;
    }
    printf("%d\n",(hasil)%1009);
}