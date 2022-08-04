#include <iostream>
#include <queue>
using namespace std;

int main(){
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        long long a=0,b=0;
        priority_queue<int> odd,even;
        for(int i=0; i<n; i++){
            int temp; cin >> temp;
            if(temp%2==0){
                even.push(temp);
            } else {
                odd.push(temp);
            }
        }
        for(int i=0; i<n; i++){
            if(i%2==1){
                //alice takes odd
                if(odd.empty()||(!even.empty() && even.top()>odd.top())){
                    even.pop();
                } else{
                    a+=odd.top();
                    odd.pop();
                }
            } else{
                if(even.empty()||(!odd.empty() &&odd.top()>even.top())){
                    odd.pop();
                } else {
                    b+=even.top();
                    even.pop();
                }
            }
        }
        //cout << a << " " << b << "\n";
        if(a<b){
            cout << "Alice\n";
        } else if(a>b){
            cout << "Bob\n";
        } else {
            cout << "Tie\n";
        }
    }
}