#include <cstdio>
#include <string>
using namespace std;
char input[100];
int main(){
    scanf("%[^\n]\n", input);
    string s = input;
    printf("%s\n", s.c_str());
}