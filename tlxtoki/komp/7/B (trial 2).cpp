#include <bits/stdc++.h>
using namespace std;
// 80/100 wtf
int pangkat(int a, int b){
    a%=1000000;
    b%=1000000;
    long long result=1;
    for(int i=0; i<b; i++){
        result%=(long)1000000;
        result*=(long)a;
        result%=(long)1000000;
    }
    return (int)result;
}

int main(){
    int a,b;
    scanf("%d %d", &a, &b);
    printf("%d\n", pangkat(a,b));
}