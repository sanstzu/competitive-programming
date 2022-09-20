#include <iostream>
#include <unordered_set>
using namespace std;
const int MOD=998244353;


int main(){
    int n; cin >> n;
    unordered_set<short> nums;
    for(int i=0; i<n; i++){
        short temp; cin >> temp;
        if(nums.count(temp)>0){
            cout << "0\n";
            return 0;
        } else {
            nums.insert(temp);
        }
    }
    long long ans=1;
    for(auto i=nums.begin(); i!=nums.end(); i++){
        for(auto j=i; j!=nums.end(); j++){
            if(j==i)continue;
            ans*=((*i)^(*j));
            ans%=MOD;
        }
    }
    cout << ans << "\n";
}