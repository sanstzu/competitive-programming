#include <iostream>
using namespace std;
const int UL = 1e8;
bool isPrime[UL];
int SPF[UL];
vector<int> prime;
void init(){
    for(int i=0; i<UL; i++) isPrime[i]=true;
    isPrime[0]=isPrime[1]=false;
    for(int i=2; i<n; i++){
        if(isPrime[i]){
            prime.push_back(i);
            SPF[i]=i;
        }
    }
}

int main(){
    
}