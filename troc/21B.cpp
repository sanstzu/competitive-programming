#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n,d; cin >> n >> d;
    int arr[n]; for(int i=0; i<n; i++) cin >> arr[i];
    int dodge[n]; for(int i=0; i<n; i++) dodge[i]=arr[i]+d;
    int i=0,j=0;
    int count = 0;
    while(i<n && j<n){
        if(arr[i]<dodge[j]){
            i++;
        } else if(arr[i]>dodge[j]){
            j++;
        } else {
            count++;
            i++; j++;
        }
    }
    cout << count << "\n";
}