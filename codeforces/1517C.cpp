#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <cmath>
#define f first
#define s second
#pragma GCC optimize ("unroll-loops")
#pragma GCC optimize ("O3")
#pragma GCC target ("sse,sse2,sse3,ssse3,sse4,abm,avx,avx2,fma,mmx,tune=native")
using namespace std;
typedef pair<int,int> pii;

int main(){
    int n; cin >> n;
    int perm[n]; for(int i=0; i<n; i++) cin >> perm[i];
    int arr[n][n]; memset(arr,-1,sizeof(arr));
    for(int i=0; i<n; i++)arr[i][i]=perm[i];
    for(int i=0; i<n; i++){
        pii ptr={i,i};
        for(int j=0; j<perm[i]-1; j++){
            
            if(ptr.f>0 && arr[ptr.f-1][ptr.s]==-1){\
                //cout << "c1\n";
                //kekiri
                arr[ptr.f-1][ptr.s]=perm[i];
                ptr.f--;
                
            } else if(ptr.s<n-1 && arr[ptr.f][ptr.s+1]==-1){
                //cout << "c2\n";
                //kabawah
                arr[ptr.f][ptr.s+1]=perm[i];
                ptr.s++;
                
            } else if(ptr.f<ptr.s && arr[ptr.f+1][ptr.s]==-1){
                //cout << "c3\n";
                //kekanan
                arr[ptr.f+1][ptr.s]=perm[i];
                ptr.f++;
                
            } else if(ptr.s>ptr.f && arr[ptr.f][ptr.s-1]==-1){
                //cout << "c4\n";
                arr[ptr.f][ptr.s-1]=perm[i];
                ptr.s--;
            } else {
                //cout  <<i << " " << j << "\n";
                //cout << ptr.f  << " " << ptr.s << "\n";
                cout << "-1\n";
                return 0;
            }
        }
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<i+1; j++){
            cout << arr[j][i] << " ";
        } cout << "\n";
    }
}