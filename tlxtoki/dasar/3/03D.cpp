#include <cstdio>
using namespace std;
int main(){
    unsigned long angka, pembagi;
    scanf("%lu %lu", &angka, &pembagi);
    unsigned long bersisa = angka%pembagi;
    unsigned long masing = angka/pembagi;
    printf("masing-masing %lu\nbersisa %lu\n", masing, bersisa);
}