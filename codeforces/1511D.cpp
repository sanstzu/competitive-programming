#include <iostream>
#include <cstring>
using namespace std;
 
int main(){
    ios::sync_with_stdio(0);
    cout.tie(0); cin.tie(0);
    int n,k; cin >> n >> k;
    int count[k][k]; memset(count,0,sizeof(count));
    int minstart[k]; memset(minstart,0,sizeof(minstart));
    char seq[n]; seq[0]='a';
    for(int i=1; i<n; i++){
        int minn=1e9, minnstart=1e9;
        int midx;
        for(int j=0; j<k; j++){
            if(minn>count[(int)(seq[i-1]-'a')][j] || (minn==count[(int)(seq[i-1]-'a')][j] && minnstart>minstart[j])){
                midx=j;
                minnstart=minstart[j];
                minn=count[(int)(seq[i-1]-'a')][j];
            }
        }
        count[(int)(seq[i-1]-'a')][midx]++;
        seq[i]=midx+'a';
        minn=1e9;
        for(int j=0; j<k; j++){
            if(minn>count[(int)(seq[i-1]-'a')][j]){
                minn=count[(int)(seq[i-1]-'a')][j];
            }
        }
        minstart[(int)(seq[i-1]-'a')]=minn;
    }
    for(int i=0; i<n; i++){
        cout << seq[i];
    }
}