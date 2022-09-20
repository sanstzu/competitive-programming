#include <cstdio>
using namespace std;
int main(){
    int N,B;
    scanf("%d %d", &N, &B);
    int height[N];
    for (int i=0;i<N;i++){
        scanf("%d", &height[i]);
    }
    int heightleft=B;
    int count=0;
    while (heightleft>0){
        int tallestvalue=0;
        int tallestindex=0;
        for(int i=0;i<N;i++)
        if(tallestvalue<height[i]){
            tallestindex=i;
            tallestvalue=height[i];
        }
        heightleft=heightleft-tallestvalue;
        count++;
        height[tallestindex]=0;
    }
    printf("%d\n",count);
}