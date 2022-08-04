#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b){
    if(b==0) return a;
    else return gcd(b,a%b);
}

int main(){
    int n; cin >> n;
    int arr[n]; int gcdd=(1<<29);
    for(int i=0; i<n; i++){
        cin >> arr[i];
        gcdd=gcd(gcdd,arr[i]);
    }
    int sum=0;
    for(int i=0; i<n; i++){
        arr[i]/=gcdd;
        sum+=arr[i];
    }
    bool failed=false;
    if(sum%2){
        cout << "0\n";
    } else {
        bitset<200005> b;
        b[0]=true;
        for(int i=0; i<n; i++){
            b|=(b<<arr[i]);
        }
        if(b[(sum>>1)]){
            cout << "1\n";
            for(int i=0; i<n; i++){
                if(arr[i]%2) {cout << i+1 << "\n";break;}
            }
        } else {
            cout << "0\n";
        }
    }
    
    
}