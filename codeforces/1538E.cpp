#include <iostream>
#include <map>
#include <cstring>
#include <vector>
#include <algorithm>
#include <string>
#pragma GCC optimize ("unroll-loops")
#pragma GCC optimize ("O3")
#pragma GCC target ("sse,sse2,sse3,ssse3,sse4,abm,avx,avx2,fma,mmx,tune=native")
using namespace std;
typedef pair<int,int> pii;
 
 
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        map<string,string> pre,suf;
        map<string,long long> arr;a
        string last;
        for(int i=0; i<n; i++){
            string var; cin >> var;
            char op; cin >> op;
            if(op==':'){
                cin >> op;
                string str; cin >> str;
                string p,s;
                p = str.substr(0,min((int)str.length(),3));
                s = str.substr(max((int)str.length()-3,0),min((int)str.length(),3));
                //cout << str << " " << p << " " << s << " " << arr[var] <<"\n";
                pre[var]=p, suf[var]=s;
                int tmp = 0;
                for(int i=3; i<str.length(); i++){
                    if(str[i]=='a' && str[i-1]=='h' && str[i-2]=='a' && str[i-3]=='h') tmp++;
                }
                arr[var]=tmp;
            } else {
                string a,b; cin >> a;
                cin >> op; cin >> b;
                string str = suf[a] + pre[b];
                int tmp=0;
                for(int i=3; i<str.length(); i++){
                    if(str[i]=='a' && str[i-1]=='h' && str[i-2]=='a' && str[i-3]=='h') tmp++;
                }
                if(str.length()>=6){
                    pre[var]=pre[a]; suf[var]=suf[b];
                } else {
                    if(suf[a].length()<3 && pre[b].length()<3){
                        pre[var]=str.substr(0,min((int)str.length(),3)); suf[var] = str.substr(max((int)str.length()-3,0),min((int)str.length(),3));
                    } else if(suf[a].length()<3){
                        pre[var]=str.substr(0,min((int)str.length(),3)); suf[var]=suf[b];
                    } else if(pre[b].length()<3){
                        pre[var]=pre[a]; suf[var] = str.substr(max((int)str.length()-3,0),min((int)str.length(),3));
                    }
                }
                arr[var] =((long long)arr[a]+ arr[b]+tmp);
                //string p = pre[var];
                //string s = suf[var];
                //cout << var << " " << str << " " << p << " " << s << " " << arr[var] << " " << arr[a] <<" " << arr[b] <<"\n";
            }
            last = var;
        }
        cout << arr[last] << "\n";
    }
}