#include <bits/stdc++.h>
using namespace std;
int cnt = 0;
int cc[2069][2069];
bool arr[2069][2069];
void dfs(int i, int j){
    if(i < 0 || j < 0 || !arr[i][j]) return;
    arr[i][j] = 0;
    dfs(i-1,j-1);
    dfs(i-1, j);
    dfs(i, j-1);
    dfs(i, j+1);
    dfs(i+1, j);
    dfs(i+1, j+1);
}

int main(){
    int n; cin >> n;
    int x[n], y[n];
    //for(int i=0; i<n; i++) for(int j=0; j<n; j++) cc[i][j] = -1;
    for(int i=0; i<n; i++) for(int j=0; j<n; j++) arr[i][j] = 0;

    for(int i=0; i<n; i++){
        cin >> x[i] >> y[i];
        x[i] += 1000;
        y[i] += 1000;
    }
    for(int i=0; i<n; i++) arr[x[i]][y[i]] = 1;

    for(int i=0; i<n; i++){
        if(arr[x[i]][y[i]]){
            cnt++;
            dfs(x[i],y[i]);
        }
    }
    cout << cnt << "\n";
}