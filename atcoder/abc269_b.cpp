#include <bits/stdc++.h>
using namespace std;

int main(){
    vector<pair<int,int>> arr;
    for(int i=0; i<10; i++){
        for(int j=0; j<10; j++){
            char tmp; cin >> tmp;
            if(tmp == '#'){
                arr.push_back({i,j});
            }
        }
    }
    int a = arr[0].first;
    int b = arr.back().first;
    int c = arr[0].second;
    int d = arr.back().second;
    cout << a+1 << " " << b+1 << "\n";
    cout << c+1 << " " << d+1 << "\n";
}