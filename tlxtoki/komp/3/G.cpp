#include <bits/stdc++.h>
using namespace std;

void merge(int A[], int low, int high, int mid){
    int a = low;
    int k = 0;
    int b = mid+1;
    int temp[high-low+1];
    while (a<=mid && b<=high){
        if(A[a]<A[b]){
            temp[k] = A[a];
            k++;
            a++;
        } else {
            temp[k] = A[b];
            k++;
            b++;
        }
    }
    while (a<=mid){
        temp[k] = A[a];
        k++;
        a++;
    }
    while (b<=high){
        temp[k] = A[b];
        k++;
        b++;
    }
    for (int i=0;i<k;i++){
        A[low+i] = temp[i];
    }
    return;
}


void mergeSort(int A[], int low, int high){
    if(low<high){
        int mid = (low + high)/2;
        mergeSort(A, low, mid);
        mergeSort(A,mid+1,high);
        merge(A, low, high, mid);
    }
}


int main(){
    //inputs the amount of numbers
    int N;
    scanf("%d", &N);
    int A[N];
    //inputs the numbers that wanted to be sort.
    for (int d=0; d<N; d++){
        scanf("%d", &A[d]);
    }
    float median;
    mergeSort(A,0,N-1);
    if (N%2==0){
        median = (float)(A[(N/2)-1] + A[N/2])/2;
    } else {
        median = A[N/2];
    }
    printf("%.1f\n", median);
    
}