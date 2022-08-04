#include <iostream>
using namespace std;

int main(){
    int t; cin >> t;
    while(t--){
        int len; cin >> len;
        int count[2]={0,0};
        char a[len]; for(int i=0; i<len; i++) {
            cin >> a[i];
            count[(int)a[i]-'0']++;
        }
        char b[len]; for(int i=0; i<len; i++) cin >> b[i];
        bool failed=false, rev=false;
        if(len%2) {
            failed=(a[len-1]!=b[len-1]);
            count[(int)a[len-1]-'0']--;
        }
        for(int i=len-len%2; i>0 && !failed; i-=2){
            bool parA=(a[i-1]==a[i-2]), parB=(b[i-1]==b[i-2]);
            if(parA!=parB || (((a[i-1]==b[i-1])==rev) && count[0]!=count[1]) ){
                failed = true;
                //cout << "failed at " << i << "\n";
            }
            if((a[i-1]!=b[i-1] && !rev) || (a[i-1]==b[i-1] && rev))rev=1-rev;
            count[(int)a[i-1]-'0']--; count[(int)a[i-2]-'0']--;
        }
        if(failed){
            cout << "NO\n";
        } else {
            cout << "YES\n";
        }
    }
}