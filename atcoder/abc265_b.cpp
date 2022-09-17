#include <bits/stdc++.h>
using namespace std;

int main(){
    long long n,m,t; cin >> n >> m >> t;
    int a[n]; for(int i=0; i<n-1; i++) cin >> a[i];
    int b[n]; for(int i=0; i<n; i++) b[i] = 0;
    for(int i=0; i<m; i++){
        int t1,t2; cin >> t1 >> t2;
        b[t1-1] = t2;
    }
    for(int i=0; i<n-1; i++){
        t-=a[i];
        //cout << t << "\n";
        if(t <= 0){
            cout << "No\n";
            return 0;
        }
        if(i<n-1)t += b[i+1];
    }
    cout << "Yes\n";
}