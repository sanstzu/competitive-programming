#include <iostream>
#include <vector>
using namespace std;

void solve(){
    int n; cin >> n;
    string str; cin >> str;
    int cnt1=0;
    for(int i=0; i<str.length(); i++)cnt1+=str[i]-'0';
    if(cnt1%2 || str[0]=='0' || str[n-1]=='0'){
        cout << "NO\n"; return;
    }
    cout << "YES\n";
    string a,b;
    bool flipped=false;
    int tcount=0;
    for(int i=0; i<str.length(); i++){
        switch(str[i]){
            case '0':
                a.push_back(flipped?')':'(');
                b.push_back(flipped?'(':')'); 
                flipped=1-flipped; 
             break;
            case '1':
                a.push_back(tcount>=(cnt1>>1)?')':'(');
                b.push_back(tcount>=(cnt1>>1)?')':'(');
                tcount++;
                break;
        }
    }
    cout << a << "\n" << b << "\n";
}

int main(){
    int t; cin >> t;
    while(t--) solve();
}