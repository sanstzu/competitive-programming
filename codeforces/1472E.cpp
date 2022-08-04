#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#define f first.first
#define s first.second
#define t second
using namespace std;
typedef pair<int,int> pii;

const int INF=1e9+7;

int main(){
    //{{a,b},idx} with a<b
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vector<pair<pii,int>> arr;
        for(int i=0; i<n; i++){
            int h,w; cin >> h >> w;
            if(h>w){
                int temp=h;
                h=w,w=temp;
            }
            arr.push_back({{h,w},i});
        }
        sort(arr.begin(), arr.end());
        int prev=1;
        vector<pii> tarr; //{b,idx}
        vector<int> ans(n,-1);
        pii smallest={INF,INF};
        for(int i=0; i<n; i++){
            if(arr[i].f>prev){
                prev=arr[i].f;
                for(pii temp: tarr){
                    if (temp.first<smallest.first){
                        smallest=temp;
                    }
                }
                tarr.clear();
            }
            tarr.push_back({arr[i].s,arr[i].t});
            if(arr[i].s>smallest.first){
                ans[arr[i].t]=smallest.second+1;
            }
        }
        for(int i=0; i<n; i++){
            cout << ans[i] << " ";
        }
        cout << "\n";
    }
}