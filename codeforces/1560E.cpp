#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <vector>
#include <string>
//#pragma GCC optimize ("unroll-loops")
//#pragma GCC optimize ("O3")
//#pragma GCC target ("sse,sse2,sse3,ssse3,sse4,abm,avx,avx2,fma,mmx,tune=native")
using namespace std;

int main(){
    //ios::sync_with_stdio(0);
    //cin.tie(0); cout.tie(0);
    int t; cin >> t;
    while(t--){
        string str; cin >> str;
        bool failed = false;
        int count[26]; memset(count,0,sizeof(count));
        int activechar = 0; 
        int originals=0;

        pair<int,int> lastseen[26];
        for(int i=0; i<26; i++){
            lastseen[i]={1e9,0};
        }
        
        for(int i=0; i<str.length(); i++) {
            count[(int)(str[i]-'a')]++;
            lastseen[(int)(str[i]-'a')]={i,(int)((char)str[i]-'a')};
        }

        for(int i=0; i<26; i++){
            if(count[i]>0){
                activechar++;
            }
        }
        
        sort(lastseen,lastseen+26);
        /*for(int i=0; i<26; i++){
            cout << lastseen[i].first << " " << lastseen[i].second << "\n";
        }*/
        
        
        
        

        
        vector<char> seq;
        cout << "original " << activechar << "\n";
        for(int i=0; i<activechar && !failed; i++){
            //cout << "ss " << i << "\n";
            if(count[lastseen[i].second]%(i+1)!=0) {
                //cout << "failed at " << i << "\n";
                failed = true;
            }   else {
                cout << count[lastseen[i].second] << "\n";
                originals += count[lastseen[i].second]/(i+1);
            }
            seq.push_back((char)lastseen[i].second+'a');
        }

        //cout << activechar << " " << originals << "\n";

        if(failed){
            cout << "-1\n";
        } else {
            string s = str.substr(0,originals);
            cout << s << " ";
            for(char i :seq){
                cout << i;
            } cout << "\n";
        }
    }
}