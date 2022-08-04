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
const int NUM = 10000;
bool isPrime[NUM];

/*
final number is always 1 digit if:
- contain 1, 4, 6, 8, 9

final number is always 2 digit if:
- two same numbers
- contain 2 not in the first digit
- contain 5 not in the first digit
237
*/

void init(){
    for(int i=0; i<NUM; i++) isPrime[i]=true;
    isPrime[0]=isPrime[1]=false;
    for(int i=2; i<NUM; i++){
        if(isPrime[i]){
            for(int j=2; i*j<NUM; j++){
                isPrime[i*j]=false;
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    init();
    int t; cin >> t;
    while(t--){
        int k; cin >> k;
        string str; cin >> str;
        if(k<5){
            int minans = 2e9;
            for(int i=1; i<(1<<k); i++){
                int temp = i, cnt = 0;
                int num = 0;
                while(temp>0){
                    if((temp%2) == 1){
                        num *= 10;
                        num += str[cnt]-'0';
                    }
                    temp>>=1; cnt++;
                }
                if(!isPrime[num]) minans = min(minans,num);
            }
            int temp = minans, digits = 0;
            while(temp>0){digits++; temp/=10;}
            cout << digits << "\n";
            cout << minans << "\n";
        } else {
            int count[10]; memset(count,0,sizeof(count));
            for(char i: str){
                count[i-'0']++;
            }
            if(count[1]){
                cout << "1\n1\n";
            } else if(count[4]){
                cout << "1\n4\n";
            } else if(count[6]){
                cout << "1\n6\n";
            } else if(count[8]){
                cout << "1\n8\n";
            } else if(count[9]){
                cout << "1\n9\n";
            } else if((str[0]!='2' && count[2]) || (count[2]>1)){
                cout << "2\n" << str[0] << "2\n";
            } else if((str[0]!='5' && count[5]) || (count[5]>1)){
                cout << "2\n" << str[0] << "5\n";
            } else {
                for(int i=1; i<10; i++){
                    if(count[i]>1){
                        cout << "2\n" << i << i << "\n";
                        break;
                    }
                }
            }
        }
    }
}

