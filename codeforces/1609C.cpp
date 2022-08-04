#include <iostream>
#include <algorithm>
#include <vector>
#define f first
#define s second
using namespace std;
typedef pair<int,int> pii;
const int MAX = 1e6+69;
bool isPrime[MAX];
void init(){
    for(int i=2; i<MAX; i++) isPrime[i]=1;
    isPrime[0]=isPrime[1]=0;
    for(int i=2; i<MAX; i++){
        if(isPrime[i]){
            for(int j=2; i*j<MAX; j++)isPrime[i*j]=0;
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cout.tie(0); cin.tie(0);
    init();
    int t; cin >> t;
    while(t--){
        int n,e; cin >> n >> e;
        int arr[n];
        for(int i=0; i<n; i++) cin >> arr[i];
        long long ans = 0;
        for(int i=0; i<e; i++){
            //cout << "for i: " << i << "\n";
            int cprev=0, cnow=0; bool prevIsPrime=false;
            for(int j=i; j<n; j+=e){
                if(arr[j]==1){
                    cnow++;
                } else if(isPrime[arr[j]]){
                    if(prevIsPrime){
                        //cout << "found prime at " << j  << "\n";
                        
                        ans+=(long long)cprev*cnow + cprev + cnow;
                    }
                    prevIsPrime=true;
                    cprev=cnow;
                    cnow=0;
                } else {
                    if(prevIsPrime){
                        //cout << "found prime at " << j  << "\n";
                        //cout << "curr var: " << cprev << ' ' << cnow << "\n";
                        ans+=(long long)cprev*cnow+ cprev + cnow;
                    }
                    prevIsPrime=false;
                    cnow=0;
                }
                //cout << "curr var: "<< cprev << ' ' << cnow << "\n";
            }
            if(prevIsPrime){
                ans+=(long long)cprev*cnow+ cprev + cnow;
            }
            //cout << "\n";
        }
        cout << ans << "\n";
    }
}