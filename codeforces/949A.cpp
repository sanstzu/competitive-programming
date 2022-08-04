#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    string str; cin >> str;
    int len=str.length();
    vector<vector<int>> arr;
    vector<int> al,ze;
    for(int i=0; i<len; i++){
        switch(str[i]){
            case '0':
                if(al.empty()){
                    vector<int> emp(1,i+1);
                    arr.push_back(emp);
                    ze.push_back(arr.size()-1);
                } else {
                    arr[al.back()].push_back(i+1);
                    ze.push_back(al.back());
                    al.pop_back();
                }
                break;
            case '1':
                if(ze.empty()){
                    cout << "-1\n";
                    return 0;
                } else {
                    arr[ze.back()].push_back(i+1);
                    al.push_back(ze.back());
                    ze.pop_back();
                }
        }
    }
    if(!al.empty()){
        cout << "-1\n";
    } else {
        cout << ze.size() << "\n";
        for(int i: ze){
            cout << arr[i].size() << " ";
            for(int j: arr[i]){
                cout << j << " ";
            }
            cout << "\n";
        }
    }
}