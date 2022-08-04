#include <iostream>
#include <iomanip>
#include <algorithm>
#include <cmath>
#include <limits>
using namespace std;

int main(){
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        int m[n], c[n];
        int ptr1=0,ptr2=0;
        for(int i=0; i<2*n ;i++){
            int x,y; cin >> x >> y;
            if(x==0){
                y=abs(y);
                m[ptr1++]=abs(y);
            } else {
                c[ptr2++]=abs(x);
            }
        }
        sort(m,m+n); sort(c,c+n);
        long double ans=0;
        for(int i=0; i<n; i++){
            ans+=sqrt((long long)m[i]*m[i]+(long long)c[i]*c[i]);
        }
        cout << setprecision(numeric_limits<long double>::digits10 + 1)
        << fixed << ans << "\n";
    }
}