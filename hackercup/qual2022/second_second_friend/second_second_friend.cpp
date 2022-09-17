#include <iostream>
#include <vector>
#define csout(x) cout << "Case #" << x << ": ";
using namespace std;
char arr[3000][3000];
bool visited[3000][3000];
bool valid[3000][3000];
int r,c;
bool dfs(int x, int y, int op){
    if(x < 0 || y < 0 || x > r-1 || y > c-1 || arr[x][y]=='#') return 0;
    if(visited[x][y]) return 1;
    //cout << "dfs(" << x << "," << y << ")\n";
    bool cnt = 0;
    visited[x][y] = 1;
    if(op!=0)cnt |= dfs(x-1, y,1);
    if(op!=1 && !cnt)cnt |= dfs(x+1, y,0);
    if(op!=2 && !cnt)cnt |= dfs(x, y-1,3);
    if(op!=3 && !cnt)cnt |= dfs(x, y+1,2);

    if(cnt){
        cout << "valid at " << x << "," << y << "\n";
        arr[x][y] = '^';
        valid[x][y] = 1;
        return true;
    }
    //cout << "invalid pos at " << x << "," << y << "\n";
    return false;
}

int main(){
    int t; cin >> t;
    for(int tc = 1; tc <= t; tc++){
        vector<pair<int,int>> trees;
        cin >> r >> c;
        bool have_tree = false;
        for(int i=0; i<r; i++){
            for(int j=0; j<c; j++){
                cin >> arr[i][j];
                visited[i][j] = false;
                valid[i][j] = false;
                if(arr[i][j]=='^'){
                    trees.push_back({i,j});
                    have_tree = true;
                }
            }
        }
        if(!have_tree){
            csout(tc);
            cout << "Possible\n";
            for(int i=0; i<r; i++){
                for(int j=0; j<c; j++){
                    cout << arr[i][j];
                }
                cout << "\n";
            }
            continue;
        }
        for(int i=0; i<r; i++){
            for(int j=0; j<c; j++){
                if(arr[i][j]=='#' || visited[i][j]) continue;
                dfs(i,j,-1);
            }
        }
        bool flag = 0;

        for(pair<int,int> pii: trees){
            if(!valid[pii.first][pii.second]){
                flag = 1;
                break;
            }
        }
        for(int i=0; i<r; i++){
            for(int j=0; j<c; j++) cout << valid[i][j];
            cout << "\n";
        }
        if(flag){
            csout(tc); cout << "Impossible\n";
        } else {
            csout(tc);
            cout << "Possible\n";
            for(int i=0; i<r; i++){
                for(int j=0; j<c; j++){
                    cout << arr[i][j];
                }
                cout << "\n";
            }
            continue;
        }
    }
}