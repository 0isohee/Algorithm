#include <iostream>
using namespace std;

int n, m, cnt = 0;
const int maxv = 1001;
bool visited[maxv];
int graph[maxv][maxv];

void DFS(int s){
    visited[s] = true;
    for (int i=1; i<=n; i++){
        if (graph[s][i] == 1 && !visited[i]) {
            DFS(i);
        }
    }
}
int main (){
    
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n >> m;
    for (int i=0; i<m; i++){
        int x,y;
        cin >> x >> y;
        graph[x][y] = 1;
        graph[y][x] = 1;
    }
    
    fill(visited, visited+maxv, false);
    for (int i=1; i<=n; i++){
        if (!visited[i]) {
            cnt ++;
            DFS(i);
        }
    }
    cout << cnt << '\n';
    
    return 0;
}