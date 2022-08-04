#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

int main(){
    int t; cin >> t;
    while(t--){
        int n,l,r,s; cin >> n >> l >> r >> s;
        if(((r-l+1)*(r-l+2)>>1)>s || (((n)*(n+1)>>1) - ((n-r+l-1)*(n-r+l)>>1))<s){
            cout << "-1\n";
            continue;
        }
        int temps=s;
        bool taken[n+1]; memset(taken,0,sizeof(taken));
        vector<int> range;
        for(int i=l; i<=r; i++){
            for(int j=n; j>0; j--){
                if(taken[j] || (temps-j)<((r-i)*(r-i+1)/2)) continue;
                //cout << i << " " << j << "\n";
                taken[j]=true;
                range.push_back(j);
                temps-=j;
                break;
            }
        }
        int ptr=1;
        for(int i=1; i<l; i++){
            while(taken[ptr])ptr++;
            taken[ptr]=true;
            cout << ptr << " ";
        }
        for(int i: range){
            cout << i << " ";
        }
        for(int i=r+1; i<=n; i++){
            while(taken[ptr])ptr++;
            taken[ptr]=true;
            cout << ptr << " ";
        }
        cout << "\n";
    }
}