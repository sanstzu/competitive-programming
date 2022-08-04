#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

void solve(){
    int a,b; cin >> a >> b;
    string str; cin >> str;
    if((a+b)%2==0 && (a%2)==1){
        cout << "-1\n";
        return ;
    } else {
        int n = a+b;
        for(int i=0; i<n; i++){
            if(str[i]=='0'){
                a--;
            } else if(str[i]=='1'){
                b--;
            }
        }
        for(int i=0; i<(n>>1); i++){
            if(str[i]==str[n-i-1]) continue;
            if(str[i]!='?' && str[n-1-i]!='?'){
                cout << "-1\n";
                return;
            } else {
                if(str[i]=='?'){
                    str[i]=str[n-i-1];
                    if(str[n-i-1]=='0'){
                        a--;
                    } else {
                        b--;
                    }
                } else {
                    str[n-1-i]=str[i];
                    if(str[i]=='0'){
                        a--;
                    } else {
                        b--;
                    }
                }
            }
            if(a<0 || b<0){
                cout << "-1\n";
                return;
            }
        }
        for(int i=0; i<(n>>1); i++){
            if(str[i]==str[n-1-i] && str[i]=='?'){
                if(a>1){
                    str[i]='0'; str[n-i-1]='0';
                    a-=2;
                } else {
                    str[i]='1'; str[n-i-1]='1';
                    b-=2;
                }
            }
        }
        if(n%2 && str[(n>>1)]=='?'){
            if(a>0){
                str[(n>>1)]='0';
                a--;
            } else {
                str[(n>>1)]='1';
                b--;
            }
        }
        if(a<0 || b<0){
            cout << "-1\n";
            return;
        }
        cout << str << "\n";
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int t; cin >> t;
    while(t--){
        solve();
    }
}