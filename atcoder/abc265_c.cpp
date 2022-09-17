#include <iostream>
using namespace std;

int main(){
    int h,w; cin >> h >> w;
    char g[h][w];

    for(int i=0; i<h; i++){
        for(int j=0; j<w; j++){
            cin >> g[i][j];
        }
    }
    int x = 0, y = 0;
    bool first = true;
    bool visited[h][w];
    for(int i=0; i<h; i++) for(int j=0; j<w; j++)visited[i][j] = false;
    while(!(visited[x][y])){
        //cout << x << " " << y << "\n";
        visited[x][y] = true;
        switch(g[x][y]){
            case 'U':
                if(x==0){
                    cout << x+1 << " " << y+1 << "\n";
                    return 0;                
                } else {
                    x--;
                }
                break;
            case 'D':
                if(x==h-1){
                    cout << x+1 << " " << y+1 << "\n";
                    return 0;                
                } else {
                    x++;
                }
                break;
            case 'L':
                if(y==0){
                    cout << x+1 << " " << y+1 << "\n";
                    return 0;                
                } else {
                    y--;
                }
                break;
            case 'R':
                if(y==w-1){
                    cout << x+1 << " " << y+1 << "\n";
                    return 0;                
                } else {
                    y++;
                }
                break;
            
        }
 
    }
    cout << "-1\n";
}