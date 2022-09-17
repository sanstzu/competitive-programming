#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;
const int NO_BITS = 31;
/*
Main idea:
- for a bit to satisfy, no of 0 in i-th bit of A = no of 1 in i-th bit of B
- greedily use the highest satisfying bit (currently)
- divides into two segment, trying to find the second highest bit that both segments satisfy
- divides again

simple way:
- sort
- if satisfy, i-th bit of a and b kth element are the same (0 or 1)
- if not, set the i-th bit to zero so it wont affect the sort of the satisfying bit
*/
int solve(vector<int> a, vector<int> b){
    int ans = 0;
    int n = a.size();
    for(int i=0; i<n; i++){
        a[i] = a[i] ^ ((1<<30)-1);
    }
    for(int i=29; i>=0; i--){
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        bool flag = false;
        for(int j=0; j<n && !flag; j++){
            if((a[j]>>i) != (b[j]>>i)) flag = true;
        }
        //cout << flag << "\n";
        if(flag){
            for(int j=0; j<n; j++){
                a[j] &= (1<<30) - 1 - (1<<i);
                b[j] &= (1<<30) - 1 - (1<<i);
            }
        } else {
            ans |= (1<<i);
        }
    }
    return ans;
}

int32_t main(){
    ios::sync_with_stdio(0);
    cout.tie(0); cin.tie(0);
    int t; cin >> t;
    //bool pass = t>3;
    while(t--){
        int n; cin >> n;
        vector<int> a(n), b(n);
        for(int i=0; i<n; i++) cin >> a[i];
        for(int i=0; i<n; i++) cin >> b[i];
        //if(pass) solve(a1,b1,30);
        /*else*/ cout << solve(a, b) << "\n";;
    }
}