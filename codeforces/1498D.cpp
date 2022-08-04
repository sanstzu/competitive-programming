#include <iostream>
#include <cmath>
#include <cstring>
using namespace std;

int main(){
    int n, m; cin >> n >> m;
    int ans[m+1]; memset(ans,-1,sizeof(ans));
    ans[0]=0;
    for(int i=0; i<n; i++){
        int t,y; long long x; cin >> t >> x >> y;
        bool visited[m+1]; memset(visited,0,sizeof(visited));
        int tempans[m+1]; memset(tempans, -1 , sizeof(tempans));
        if(t==1){
            for(int j=m; j>=0; j--){
                if(visited[j] || ans[j]==-1) continue;
                visited[j]=true;
                if(ans[j]==-1)ans[j]=(i+1);
                long long temp=j;
                long long dif=(x+99999)/100000;
                for(int a=0; a<y; a++){
                    temp+=dif;
                    if(temp>m || visited[temp])break;
                    visited[temp]=true; 
                    if(ans[temp]==-1)tempans[temp]=(i+1);
                }
            }
        } else {
            for(int j=m; j>0; j--){
                if(visited[j] || ans[j]==-1) continue;
                visited[j]=true;
                if(ans[j]==-1)ans[j]=(i+1);
                long long temp=j;
                for(int a=0; a<y; a++){
                    temp=(temp*x+99999)/100000;
                    if(temp>m || visited[temp])break;
                    visited[temp]=true;
                    if(ans[temp]==-1)tempans[temp]=(i+1);
                }
            }
        }
        for(int j=1; j<=m; j++){
            if(tempans[j]==-1) continue;
            ans[j]=tempans[j];
        }
    }
    
    for(int i=1; i<=m; i++){
        cout << ans[i] << " ";
    }cout << "\n";
    
   
}