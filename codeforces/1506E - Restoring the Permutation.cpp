#include <iostream>
#include <set>
#include <vector>
using namespace std;

void solve(){
    int n; cin >> n; bool taken[200001]; for(int i=0; i<200001; i++) taken[i]=false;
    int arr[n];for(int i=0; i<n; i++){
        cin >> arr[i];
        taken[arr[i]]=true;
    }
    set<int> minn,maxx;
    for(int i=1; i<=n; i++){
        if(taken[i]) continue;
        minn.insert(i);
    }
    maxx=minn;
    vector<int> miarr, maarr;
    
    miarr.push_back(arr[0]);
    maarr=miarr;
    int last=arr[0], lidx=0;
    for(int i=1; i<n; i++){
        if(arr[i]==last)continue;
        int width=i-lidx-1;
        
        for(int j=0; j<width; j++){
            //cout << i << " " <<j << " " << last << " " << lidx << "\n";
            auto miptr=minn.upper_bound(0);
            //cout << 'z';
            auto maptr = maxx.lower_bound(last);
            maptr--;
            //cout << 'a';
            miarr.push_back((int)*miptr);
            //cout << 'b';
            maarr.push_back((int)*maptr);
            //cout << 'c';
            minn.erase(miptr); maxx.erase(maptr);
            //cout << "d\n";
            /*
            cout << "minn: ";
            for(int i: minn){
                cout << i << " ";
            } cout << "\n";
            cout << "maxx: ";
            for(int i: maxx){
                cout << i << " ";
            } cout << "\n";\
            */
        }
        miarr.push_back(arr[i]);
        maarr.push_back(arr[i]);
        last=arr[i]; lidx=i;
    }
    //cout << 2;
    for(int i=0; i<(n-1-lidx); i++){
        auto miptr=minn.upper_bound(0), maptr = maxx.lower_bound(last);
        maptr--;
        miarr.push_back((int)*miptr);
        maarr.push_back((int)*maptr);
        minn.erase(miptr); maxx.erase(maptr);
    }
    for(int i: miarr){
        cout << i << " ";
    }cout << "\n";
    for(int i: maarr){
        cout << i << " ";
    }cout << "\n";
}

int main(){
    int t; cin >> t;
    while(t--) solve();
}