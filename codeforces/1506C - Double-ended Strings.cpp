#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

bool equal(string a, string b){
    if(a.length()!=b.length()) return false;
    int sz=a.length();
    bool same=true;
    for(int i=0; i<sz && same; i++) same = (a[i]==b[i]);
    return same;
}

void solve(){
    string a,b; cin >> a >> b;
    int asz=a.length(), bsz=b.length();
    int msize=min(asz,bsz);
    int ans=asz+bsz;
    for(int slen=1; slen<=msize; slen++){
        bool found = false;
        for(int i=0; i<asz-slen+1 && !found; i++){
            for(int j=0; j<bsz-slen+1 && !found; j++){
                string ta=a.substr(i,slen), tb=b.substr(j,slen);
                found = equal(ta,tb);
            }
        }
        if(found){
            ans=asz+bsz-2*slen;
        }
    }
    cout << ans << '\n';
}

int main(){
    int t; cin >> t;
    while(t--)solve();
}