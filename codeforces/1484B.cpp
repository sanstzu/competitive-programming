#include <iostream>
#include <queue>
using namespace std;
 
void solve(){
    int n; cin >> n;
    int arr[n]; for(int i=0; i<n; i++) cin >> arr[i];
    int c = -1, m = -1;
    bool failed=false, p=false, mm=false;;
    for(int i=1; i<n && !failed; i++){
        int temp=arr[i]-arr[i-1];
        if(temp<0) continue;
        p=true;
        if(c==-1) c=temp;
        else if(temp!=c) failed=true;
    }
    if(failed){
        cout << "-1\n";
        return;
    }
    for(int i=1; i<n && !failed; i++){
        int temp = arr[i] - arr[i-1];
        if(temp>=0) continue;
        mm=true;
        if(m==-1) m = c - temp;
        else if(m!=c - temp) failed= true;
    }
    for(int i=0; i<n && !failed && m!=-1 && c!=-1; i++){
        if(arr[i]>=m) failed=true;
    }
    if(failed){
        cout << "-1\n";
    } else if(!p || !mm){
        cout << "0\n";
    } else {
        cout << m << " " << c << "\n";
    }
}
 
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t; cin >> t;
    while(t--)solve();
}