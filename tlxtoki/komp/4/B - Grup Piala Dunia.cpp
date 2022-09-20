#include <bits/stdc++.h>
using namespace std;

/*
Rules and criteria:
- Sum of games for each team = n - 1
- No. of wins must be decreasing

x = win, y = lose, z = tie

3xi + zi = k[i]
2x + z = n-1

x = k[i] - n-1
*/
int fp(int a, int b){
    if(b==0) return 1;
    else if(b%2){
        return a*fp(a,b-1);
    } else {
        int res = fp(a,b>>1);
        return res*res;
    }
}

int main(){
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        int arr[n]; for(int i=0; i<n; i++) cin >> arr[i];
        sort(arr,arr+n);
        int no_of_games = (n*(n-1))>>1;
        int ul = fp(3,no_of_games);
        bool found = false;
        for(int com_no = 0; com_no <ul && !found; com_no++){
            int tmp_com = com_no;
            int temp[n]; memset(temp,0,sizeof(temp));
            for(int i=0; i<n; i++){
                for(int j=i+1; j<n; j++){
                    //out << com_no << " " << i << " " << j << "\n";
                    if(tmp_com%3==0){
                        //i wins j loses
                        temp[i] += 3;
                    } else if(tmp_com%3==1){
                        //j wins
                        temp[j] += 3;
                    } else {
                        temp[i]++;
                        temp[j]++;
                    }
                    tmp_com /= 3;
                }
            }
            sort(temp,temp+n);
            bool flag = true;
            for(int i=0; i<n; i++){
                flag &= (arr[i]==temp[i]);
            }
            if(flag) found = true;
            /*
            if(fflag){
                for(int i=0; i<n; i++) cout << temp[i] << " ";
                cout << "\n";
                 for(int i=0; i<n; i++) cout << arr[i] << " ";
                cout << "\n";
            } 
            */
        }
        if(found) cout << "YES\n";
        else cout << "NO\n";
    }
}