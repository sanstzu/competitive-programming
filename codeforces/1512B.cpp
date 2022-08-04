#include <iostream>
#include <cstring>
#define f first
#define s second
using namespace std;
typedef pair<int,int> pii;

int main(){
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        pii ss[2];
        char arr[n][n];
        int cnt=0;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                char temp; cin >> temp;
                arr[i][j]=temp;
                if(temp=='.') continue;
                ss[cnt].f=i; ss[cnt++].s=j;
            }
        }
        if(ss[0].f==ss[1].f){
            arr[(ss[0].f+1)%n][ss[0].s]='*';
            arr[(ss[1].f+1)%n][ss[1].s]='*';
        } else if(ss[0].s==ss[1].s){
            arr[ss[0].f][(ss[0].s+1)%n]='*';
            arr[ss[1].f][(ss[1].s+1)%n]='*';
        } else {
            arr[ss[0].f][ss[1].s]='*';
            arr[ss[1].f][ss[0].s]='*';        
        }
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                cout << arr[i][j];
            }cout << "\n";
        }
    }
}