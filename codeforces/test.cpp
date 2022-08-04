#include <iostream>
#include <bitset>
#include <cstring>
using namespace std;

int main(){
    cout << "1\n200000 1\n";
    for(int i=0; i<100000; i++) cout << "1 ";
    for(int i=0; i<99999; i++) cout << "1 ";
    cout << "2 ";
}