#include <iostream>
#include <string>
using namespace std;
const int MOD=1e9+7;
inline int sum(int a, int b){
    return ((long long)a+b)%MOD;
}
inline int mul(int a, int b){
    return ((long long)a*b)%MOD;
}
int power (int a, int b){
    if(b==0) return 1;
    if(b%2==1){
        return mul(a,power(a,b-1));
    } else {
        int res = power(a,(b>>1));
        return mul(res,res);
    }
}


int main(){
    string num; cin >> num;
    int n=num.length();
    int ans=0,multiplier=0,tens=1;
    int invhalf=power(2,MOD-2);

    for(int i=n-1; i>=0; i--){
        ans=sum(ans,sum(mul(mul(mul(i,i+1),invhalf),mul(((int)num[i]-'0'),tens)),mul(multiplier,((int)num[i]-'0'))));
        multiplier=sum(multiplier,mul(tens,n-1-i+1));
        tens=mul(tens,10);
        //cout << ans << " " << multiplier << " " << tens << "\n";
    }
    cout << ans << "\n";
}