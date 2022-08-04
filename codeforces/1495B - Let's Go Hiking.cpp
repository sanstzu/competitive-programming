#include <iostream>
#include <vector>
#include <algorithm>
#define f first
#define s second
using namespace std;
typedef pair<int,int> pii;
/* Main idea
    To maximize the time walking up or walking down, each players must start on the peak
    (for Qingshan) or the bottom part (for Daniel). The most optimal way for Daniel to win
    is for him to block Qingshan's path down the hill. Let x be the bottom, y is the peak that
    Qingshan picked.
    If |y-x+1| is even, then Daniel will start at x since at the middle he would block Qinghsan.
    While if it is odd, then Daniel will start at x-1 in order to block her.
    In order to win, Q must start on a peak where the |Left| = |Right| and it is odd;
*/
/*
.
⣿⣿⣿⣿⣿⠟⠋⠄⠄⠄⠄⠄⠄⠄⢁⠈⢻⢿⣿⣿⣿⣿⣿⣿⣿
⣿⣿⣿⣿⣿⠃⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠈⡀⠭⢿⣿⣿⣿⣿
⣿⣿⣿⣿⡟⠄⢀⣾⣿⣿⣿⣷⣶⣿⣷⣶⣶⡆⠄⠄⠄⣿⣿⣿⣿
⣿⣿⣿⣿⡇⢀⣼⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣧⠄⠄⢸⣿⣿⣿⣿
⣿⣿⣿⣿⣇⣼⣿⣿⠿⠶⠙⣿⡟⠡⣴⣿⣽⣿⣧⠄⢸⣿⣿⣿⣿
⣿⣿⣿⣿⣿⣾⣿⣿⣟⣭⣾⣿⣷⣶⣶⣴⣶⣿⣿⢄⣿⣿⣿⣿⣿
⣿⣿⣿⣿⣿⣿⣿⣿⡟⣩⣿⣿⣿⡏⢻⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿
⣿⣿⣿⣿⣿⣿⣹⡋⠘⠷⣦⣀⣠⡶⠁⠈⠁⠄⣿⣿⣿⣿⣿⣿⣿
⣿⣿⣿⣿⣿⣿⣍⠃⣴⣶⡔⠒⠄⣠⢀⠄⠄⠄⡨⣿⣿⣿⣿⣿⣿
⣿⣿⣿⣿⣿⣿⣿⣦⡘⠿⣷⣿⠿⠟⠃⠄⠄⣠⡇⠈⠻⣿⣿⣿⣿
⣿⣿⣿⣿⡿⠟⠋⢁⣷⣠⠄⠄⠄⠄⣀⣠⣾⡟⠄⠄⠄⠄⠉⠙⠻
⡿⠟⠋⠁⠄⠄⠄⢸⣿⣿⡯⢓⣴⣾⣿⣿⡟⠄⠄⠄⠄⠄⠄⠄⠄
⠄⠄⠄⠄⠄⠄⠄⣿⡟⣷⠄⠹⣿⣿⣿⡿⠁⠄⠄⠄⠄⠄⠄⠄⠄
⠄⠄⠄⠄⠄⠄⣸⣿⡷⡇⠄⣴⣾⣿⣿⠃⠄⠄⠄⠄⠄⠄⠄⠄⠄
⠄⠄⠄⠄⠄⠄⣿⣿⠃⣦⣄⣿⣿⣿⠇⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄
⠄⠄⠄⠄⠄⢸⣿⠗⢈⡶⣷⣿⣿⡏⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄
*/
int main(){
    int n; cin >> n;
    int arr[n]; for(int i=0; i<n; i++) cin >> arr[i];
    int maxi=0,prevpeak=-1,prevbottom=-1;
    vector<pii> peaks;
    for(int i=0; i<n; i++){
        if((i==n-1 ||arr[i]>arr[i+1]) && (i==0 || arr[i]>arr[i-1])){
            //cout << "a " << i << "\n";
            prevpeak=i;
            if(i==n-1){
                pii temp; temp.f=prevpeak-prevbottom+1; temp.s=-1;
                peaks.push_back(temp);
            }
        } else if((i==n-1 || arr[i]<arr[i+1]) && (i==0 || arr[i]<arr[i-1])){
            //cout << "b " << i << "\n";
            pii temp; temp.f=prevpeak-prevbottom+1; temp.s=i-prevpeak+1;
            if(prevbottom==-1)temp.f=-1;
            if(prevpeak==-1)temp.s=-1;
            maxi=max(maxi,max(temp.f,temp.s));
            prevbottom=i;
            peaks.push_back(temp);
        }
    }
    /*
    for(pii i: peaks){
        cout << i.f << " " << i.s << "\n";
    }
    */
    if(maxi%2==0){
        cout << "0\n";
    } else {
        int ans=0;
        bool prevmax=false,failed=false;;
        for(pii i: peaks){
            if(i.f==i.s && i.f==maxi && !prevmax){
                ans++;
            }
            if(i.f==maxi || i.s==maxi){
                if(prevmax) failed=true;
                prevmax=true;
            }
        }
        cout << (failed?0:ans) << "\n";
    }
    
}