#include <bits/stdc++.h>
using namespace std;

int main(){
    long long n;
    cin >> n;
    vector<long long> pos;
    for(int i=0; i<60; i++){
        if((n>>i)%2) pos.push_back(((long long)1<<i));
    }
    for(int i=0; i<(1<<((int)pos.size())); i++){
        int temp = i;
        long long ans = 0;
        for(int j=0; j<(int)pos.size(); j++){
            if((i>>j)%2) ans += pos[j];
        }
        cout << ans << "\n";
    }
}