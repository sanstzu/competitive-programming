#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <queue>
#include <vector>
#pragma GCC optimize ("unroll-loops")
#pragma GCC optimize ("O3")
#pragma GCC target ("sse,sse2,sse3,ssse3,sse4,abm,avx,avx2,fma,mmx,tune=native")
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        deque<int> arr[2];
        deque<int> pq[2];
        for(int i=0; i<n; i++){
            int temp; cin >> temp;
            temp%=2;
            arr[temp].push_back(i);
        }
        if(abs((int)arr[0].size()-(int)arr[1].size())>1){
            cout << "-1\n";
        } else if(n==1 || n==2){
            cout << "0\n";
        } else {
            int ans = 2e9;
            //starts with odd;
            pq[0]=arr[0]; pq[1]=arr[1];
            //cout << 0 << "c\n";
            if(((int)pq[1].size()-(int)pq[0].size())>=0){
                int tans = 0;
                for(int i=0; i<n; i++){
                    //cout << i << "c\n";
                    //cout << (pq[0].size()?pq[0].front():-1) << " " << (pq[1].size()?pq[1].front():-1) << "\n";
                    if((pq[i%2].size() != 0) || pq[(i+1)%2].front()>pq[i%2].front()){
                        //the parity is not the same
                        int ttop = pq[(i+1)%2].front();
                        pq[(i+1)%2].pop_front();
                        vector<int> tarr;
                        while(pq[i%2].size() && (pq[i%2].front()<ttop)){
                            tarr.push_back(pq[i%2].front()+1);
                            pq[i%2].pop_front();
                        }

                        //TLE MAKER
                        while(tarr.size()){
                            pq[i%2].push_front(tarr.back());
                            tarr.pop_back();
                        }
                        tans += ttop-i;
                    } else {
                        pq[(i+1)%2].pop_front();
                    }
                }
                ans = min(ans, tans);
            }
            //cout << 1 << "c\n";
            pq[0]=arr[0]; pq[1]=arr[1];
            if(((int)pq[0].size()-(int)pq[1].size())>=0){
                int tans = 0;
                for(int i=0; i<n; i++){
                    //cout << (pq[0].size()?pq[0].front():-1) << " " << (pq[1].size()?pq[1].front():-1) << "\n";
                    //cout << "n" << i << "\n";
                    if((pq[(i+1)%2].size() != 0) || pq[i%2].front()>pq[(i+1)%2].front()){
                        //the parity is not the same
                        //cout << 2 << "d\n";
                        int ttop = pq[i%2].front();
                        pq[i%2].pop_front();
                        vector<int> tarr;
                        //cout << ttop << "t\n";
                        //cout << 3 << "d\n";
                        while(pq[(i+1)%2].size() && (pq[(i+1)%2].front()<ttop)){
                            tarr.push_back(pq[(i+1)%2].front()+1);
                            pq[(i+1)%2].pop_front();
                        }
                        //cout << 4 << "d\n";
                        //TLE MAKER
                        while(tarr.size()){
                            pq[(i+1)%2].push_front(tarr.back());
                            tarr.pop_back();
                        }
                        //cout << 5 << "d\n";
                        tans += ttop-i;
                    } else {
                        pq[i%2].pop_front();
                    }
                }
                ans = min(ans, tans);
            }
            //cout << 2 << "c\n";
            cout << ans << "\n";
        }
        
    }
}

