#include <iostream>
#include <queue>
#include <stack>
#include <map>
#include <algorithm>
using namespace std;

void printQ(queue<int> arr){
    stack<int> temp;
    while(arr.size()){
        temp.push(arr.front()); arr.pop();
    }
    while(temp.size()){
        cout << temp.top() << " ";
        temp.pop();
    } cout << "\n";
}

int main(){
    int n,k; cin >> n >> k;
    int seq[n]; for(int i=0; i<n; i++) cin >> seq[i];
    int cur=-1,qsize=min(n,k);
    queue<int> msglist;
    map<int,bool> taken;
    for(int i=0; i<n; i++){
        if(!taken[seq[i]]){
            msglist.push(seq[i]);
            taken[seq[i]]=1;
        }
        if(msglist.size()>k){taken[msglist.front()]=0;msglist.pop();}
    }
    cout << msglist.size() << "\n";
    printQ(msglist);
}