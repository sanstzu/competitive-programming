#include <iostream>
#include <map>
using namespace std;

int main(){
    int n; cin >> n;
    string a,b; cin >> a >> b;
    int ans=0;
    for(int i=0; i<(n>>1); i++){
        map<char,int> arr;
        arr[a[i]]++; arr[b[i]]++;
        arr[a[n-i-1]]++; arr[b[n-i-1]]++;
        //arr.insert(a[i]); arr.insert(b[i]);
        //arr.insert(a[n-i-1]); arr.insert(b[n-i-1]);
        int temp=arr.size();
        if(temp==4){
            //cout << "0: ";
            ans+=2;
        } else if(temp==3){
            //cout << "1: ";
            ans+=1 + (a[i]==a[n-i-1]);
        } else if(temp==2){
            //cout << "2: ";
            ans += (arr[a[i]]!=2);
        }
        //cout << ans << "\n";
    }
    if(n%2==1 && a[n>>1]!=b[n>>1]){
        map<char,int> arr;
        arr[a[n>>1]-1]++; arr[b[n>>1]-1]++;
        ans+=max(0,(int)arr.size()-1);
    }
    cout << ans << "\n";
}