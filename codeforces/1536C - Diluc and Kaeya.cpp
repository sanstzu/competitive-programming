#include <iostream>
#include <map>
#include <cstring>
#define f first
#define s second
using namespace std;
typedef pair<int,int> pii;
int gcd(int a, int b){
    if (b==0) return a;
    else return gcd(b,a%b);
}

int main(){
    ios::sync_with_stdio(0);
    cout.tie(0); cin.tie(0);
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        int arr[n]; //count how many D
        for(int i=0; i<n; i++){
            char temp; cin >> temp;
            if(temp=='D')arr[i]=1;
            else arr[i]=0;
            if(i>0) arr[i]+=arr[i-1];
        }
        map<pii,int> dp;
        for(int i=0; i<n; i++){
            int gcdd = gcd(arr[i],i+1);
            pii ratio = {arr[i]/gcdd,(i+1)/gcdd};
            cout << ++dp[ratio] << " ";
        }
        cout << "\n";
    }
}