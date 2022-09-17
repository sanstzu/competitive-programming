#include <bits/stdc++.h>

using namespace std;
typedef pair<int,double> pid;
typedef pair<double,int> pdi;

vector<vector<pdi>> adj;
int n_size;

void cons(int x){
    n_size = x;
    adj = vector<vector<pdi>>(n_size);
}

void add_adj(int a, int b, double w){
    adj[a].push_back({w,b});
    adj[b].push_back({w,a});
}

double shortest_path(int a, int b){
    //bool visited[n];
    //cout << "2.5\n" << n_size << "\n";;
    vector<double> cur(n_size,1e9);
    //for(int i=0; i<n_size; i++) cur[i] = 1e9;
    //for(int i=0; i<n; i++) visited[i] = 0;
    cur[a] = 0;
    //cout << "3\n";
    priority_queue<pdi, vector<pdi>, greater<pdi>> pq;
    pdi tmp = {0,a};
    pq.push(tmp);
    //cout << "4\n";
    while(!pq.empty()){
        pdi cur_node = pq.top();
        pq.pop();
        //if(visited[cur_node.second]) continue;
        //visited[cur_node.]
        //out << "{" << cur_node.first << "," << cur_node.second << "}\n";
        for(pdi next: adj[cur_node.second]){
            if(cur[cur_node.second] + next.first < cur[next.second]){
                cur[next.second] = cur[cur_node.second] + next.first;
                pdi tempor = {cur[next.second], next.second};
                pq.push(tempor);
            }
        }
    }
    return cur[b];
}
int a[105], b[105], k[105];
int n=1, m=1, d=1;
bool bsta(double mid){
    //cout << "1\n" << mid << "\n";
    cons(n);
    for(int i=0; i<m; i++){
        double dist = (mid/((double)k[i]));
        add_adj(a[i], b[i], dist);
        //cout << dist << "--\n";
    }
    //cout << "2\n";
    /*
    for(vector<pdi> tmp: arr.adj){
        cout << "{";
        for(pdi tmpp: tmp){
            cout << "{" << tmpp.first << "," << tmpp.second << "} , ";
        }
        cout << "}\n";
    }
    */
    return (shortest_path(0,n-1) >= (double)d);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    while(n!=0 || m!=0 || d!=0){
        cin >> n >> m >> d;
        if(n==0 && m==0 && d==0) continue;
        
        for(int i=0; i<m; i++){
           cin >> a[i] >> b[i] >> k[i];
        }
        double l = 0, r = 1e11;
        while(r-l > 1e-3){
            //cout << l << " " << r << "\n";
            double mid = (l+r)/2;
            if(bsta(mid)){
                r = mid;
            } else {
                l = mid;
            }
        }
        cout << fixed << setprecision(2) << l << "\n";
    }
    return 0;
}
