#include <iostream>
#include <bits/stdc++.h>
using namespace std;


int main(){
    int n,k; cin >> n >> k;
    vector<vector<int>> arr;
    map<vector<int>,int> exists;
    arr.assign(n,vector<int>(k,0));
    for(int i=0; i<n; i++){
        for(int j=0; j<k; j++){
            char temp; cin >> temp;
            switch(temp){
                case 'S':
                    arr[i][j]=0;
                    break;
                case 'E':
                    arr[i][j]=1;
                    break;
                case 'T':
                    arr[i][j]=2;
                    break;
            }
        }
    }
    for(int i=0; i<n; i++){
        exists[arr[i]]=i;
    }
    int ans=0;
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            vector<int> temp(k,0);
            for(int l=0; l<k; l++){
                if(arr[i][l]==arr[j][l]){
                    temp[l]=arr[i][l];
                } else {
                    temp[l]=3-arr[i][l]-arr[j][l];
                }
            }
            if(exists.count(temp)>0 && exists[temp]>j){
                ans++;
            }
        }
    }
    cout << ans << "\n";    
}