#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <vector>
#include <string>
#pragma GCC optimize ("unroll-loops")
#pragma GCC optimize ("O3")
#pragma GCC target ("sse,sse2,sse3,ssse3,sse4,abm,avx,avx2,fma,mmx,tune=native")
using namespace std;

// seas of 1s
// other zero other than in the middle
// symmetry
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t; cin >> t;
    while(t--){
        int n; cin >> n; char arr[n]; 
        for(int i=0; i<n; i++) cin >> arr[i];
        vector<int> segs;
        int cnt = 0;
        bool s0 = arr[0]=='0';
        bool previszero = s0;
        for(int i=0; i<n; i++){
            if((previszero && arr[i]=='1') || (!previszero && arr[i]=='0')){
                segs.push_back(cnt); cnt=0;
                previszero = arr[i]=='0';
            }
            cnt++;
        }
        if(cnt>0) segs.push_back(cnt);
        if(segs.size()==1){
            //seas of 1s or 0s
            cout << "1 " << n-1 << " 2 " << n << "\n";
        } else if(segs.size()==3 && !s0 && segs[1]==1 && segs[0]==segs[2]){
            //symmetry (11..101..11)
            cout << "1 " << n/2 +1 << " " << n/2 + 1 << " " << n << "\n";
        } else {
            // other zero than in middle
            int left = 0, right = n;
            for(int i=0; i<segs.size(); i++){
                //checks if its a group of 0
                right-=segs[i];
                if((i+1)%2 == s0){
                    if((left + segs[i]-1) >= n/2){
                        cout << 1 << " " << left + segs[i] << " " << 1 << " " << left + segs[i]-1 << "\n";
                        break;
                    } else if((right + segs[i]-1)>= n/2){
                        cout << left + 1 << " " << n << " " << left+2 << " " << n << "\n";
                        break;
                    }
                }
                left+=segs[i];
            }
        }
    }
}

