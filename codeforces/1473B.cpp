#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b){
    if(b == 0) return a;
    return gcd(b,a%b);
}

int main(){
    int q; cin >> q;
    while(q--){
        string a,b; cin >> a >> b;
        string sa=a,sb=b;
        int ca=1,cb=1;
        bool founded=false;
        for(int i=1; i<=(a.length()>>1) && !founded; i++){
            if(a.length()%i)continue;
            string subtemp=a.substr(0,i);
            founded=true;
            for(int j=i; j<a.length(); j+=i){
                if(a.substr(j,i)!=subtemp)founded=false;
            }
            if(founded){
                sa=subtemp; ca=a.length()/i;
            }
        }
        founded=false;
        for(int i=1; i<=(b.length()>>1) && !founded; i++){
            if(b.length()%i)continue;
            string subtemp=b.substr(0,i);
            founded=true;
            for(int j=i; j<b.length(); j+=i){
                if(b.substr(j,i)!=subtemp)founded=false;
            }
            if(founded){
                sb=subtemp; cb=b.length()/i;
            }
        }
        //cout << sa << " " << sb << "\n";
        if(sa==sb){
            int lcm=(ca/gcd(ca,cb))*cb;
            for(int i=0; i<lcm; i++){
                cout << sa;
            }
            cout << "\n";
        } else {
            cout << "-1\n";
        }

    }
}